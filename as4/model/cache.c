#include "cache.h"
#include "dogfault.h"
#include <assert.h>
#include <ctype.h>
#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// DO NOT MODIFY THIS FILE. INVOKE AFTER EACH ACCESS FROM runTrace
void print_result(result r) {
  if (r.status == CACHE_EVICT)
    printf(" [status: %d victim_block: 0x%llx insert_block: 0x%llx]", r.status,
           r.victim_block, r.insert_block);
  if (r.status == CACHE_HIT)
    printf(" [status: %d]", r.status);
  if (r.status == CACHE_MISS)
    printf(" [status: %d insert_block: 0x%llx]", r.status, r.insert_block);
}

// HELPER FUNCTIONS USEFUL FOR IMPLEMENTING THE CACHE
// Convert address to block address. 0s out the bottom block bits.
unsigned long long address_to_block(const unsigned long long address,
                                const Cache *cache) {
  unsigned long long add;
  add = address >> cache->blockBits << cache->blockBits;
  return add;
}

// Access address in cache. Called only if probe is successful.
// Update the LRU (least recently used) or MFU (most frequently used) counters.
void access_cache(const unsigned long long address, const Cache *cache) {
  unsigned long long index = cache_set(address, cache);
  Set set = cache->sets[index];
  set.recentRate ++;
  return;
}

// Calculate the tag of the address. 0s out the bottom set bits and the bottom block bits.
unsigned long long cache_tag(const unsigned long long address,
                             const Cache *cache) {
  unsigned long long tag;
  tag = address >> (cache->blockBits + cache->setBits) << (cache->blockBits + cache->setBits);
  return tag;
}

// Calculate the set of the address. 0s out the bottom block bits, 0s out the tag bits, and then shift the set bits to the right.
unsigned long long cache_set(const unsigned long long address,
                             const Cache *cache) {
  unsigned long long set = 0;
  for(int i = 0; i < cache->setBits; i++){
    set <<= 1;
    set += 1;
  }
  set = ((set << cache->blockBits) & address) >> cache->blockBits;
  return set;
}

// Check if the address is found in the cache. If so, return true. else return false.
bool probe_cache(const unsigned long long address, const Cache *cache) {
  unsigned long long index = cache_set(address, cache);
  unsigned long long tag = cache_tag(address, cache);
  for(int i = 0; i < cache->linesPerSet; i++){
    if(cache->sets[index].lines[i].valid && cache->sets[index].lines[i].tag == tag){
      return true;
    }
  }
  return false;
}

// Allocate an entry for the address. If the cache is full, evict an entry to create space. This method will not fail. When method runs there should have already been space created. 
void allocate_cache(const unsigned long long address, const Cache *cache) {
  unsigned long long index = cache_set(address, cache);
  unsigned long long tag = cache_tag(address, cache);
  Set set = cache->sets[index];
  for(int i = 0; i < cache->linesPerSet; i++){
    if(set.lines[i].valid == 0){
      set.lines[i].valid = 1;
      set.lines[i].tag = tag;
      set.lines[i].block_addr = address_to_block(address, cache);
      set.lines[i].r_rate = set.recentRate;
      return;
    }
  }
}

// Is there space available in the set corresponding to the address?
bool avail_cache(const unsigned long long address, const Cache *cache) {
  // calculate tag and set values
  unsigned long long index = cache_set(address, cache);
  Set set = cache->sets[index];
  for(int i = 0; i < cache->linesPerSet; i++){
    if(set.lines[i].valid == 0){
      return true;
    }
  }
  return false;
}

// If the cache is full, evict an entry to create space. This method figures out which entry to evict. Depends on the policy.
unsigned long long victim_cache(const unsigned long long address,
                                Cache *cache) {
  unsigned long long index = cache_set(address, cache);
  Set set = cache->sets[index];
  int minUses = set.lines[0].r_rate;
  unsigned long long LRU = 0;
  for(int i = 0; i < cache->linesPerSet; i++){
    if(set.lines[i].r_rate < minUses){
      LRU = i;
      minUses = set.lines[i].r_rate;
    }
  }
  return LRU;
}

// Set can be determined by the address. Way is determined by policy and set by the operate cache. 
void evict_cache(const unsigned long long address, int way, Cache *cache) {
  unsigned long long index = cache_set(address, cache);
  cache->sets[index].lines[way].valid = 0;
  return;
}

// Given a block address, find it in the cache and when found remove it.
// If not found don't remove it. Useful when implementing 2-level policies. 
// and triggering evictions from other caches. 
void flush_cache(const unsigned long long block_address, Cache *cache) {
  unsigned long long index = cache_set(block_address, cache);
  unsigned long long tag = cache_tag(block_address, cache);
  Set set = cache->sets[index];
  for(int i = 0; i < cache->linesPerSet; i++){
    if(set.lines[i].tag == tag){
      set.lines[i].valid = 0;
    }
  }
  return;
}
// checks if the address is in the cache, if not and if the cache is full
// evicts an address
result operateCache(const unsigned long long address, Cache *cache) {
  // checkCache checks if the address is in the cache
  unsigned long long index = cache_set(address, cache);
  result r;
  r.status = 1;

  if(probe_cache(address, cache)){ // block is in cache.
    access_cache(address, cache);
    r.status = 1;
    cache->hit_count ++;
  }
  else{
    if(avail_cache(address, cache)){ //miss and allocate
      allocate_cache(address, cache);
      r.status = 0;
    }else{    // miss and eviction and allocate
      int way = victim_cache(address, cache);
      r.victim_block = cache->sets[index].lines[way].block_addr;
      evict_cache(address, way, cache);
      allocate_cache(address, cache);
      cache->eviction_count ++;
      r.status = 2;
    }
    cache->miss_count ++;
    r.insert_block = address_to_block(address, cache);
  }
  
  // Hit
    if (cache->displayTrace && r.status == 1){
      printf(" %s hit ", cache->name);
    }
    if (cache->displayTrace && r.status == 2){
      printf(" %s miss eviction ", cache->name);
    }
    if (cache->displayTrace && r.status == 0){
      printf(" %s miss ", cache->name);
    }
        
  return r;
}

// initialize the cache and allocate space for it
void cacheSetUp(Cache *cache, char *name) {
  Set set;
  Line line;

  cache->name = name;
  cache->eviction_count = 0;
  cache->hit_count = 0;
  cache->miss_count = 0;
  cache->sets = (Set*)malloc(sizeof(Set) * (1 << cache->setBits));
  for(int i = 0; i < (1 << cache->setBits); i++){
    set.lines = (Line*)malloc(sizeof(Line) * cache->linesPerSet);
    set.placementRate = 0;
    set.recentRate = 0;
    cache->sets[i] = set;

    for(int j = 0; j < cache->linesPerSet; j++){
      line.valid = 0;
      line.tag = 0;
      line.r_rate = 0;
      line.block_addr = 0x0;
      set.lines[j] = line;
    }
  }
}

// deallocate memory
void deallocate(Cache *cache) {
  for(int i = 0; i < cache->linesPerSet; i++){
    Set set = cache->sets[i];
    if(set.lines != NULL){
      free(set.lines);
    }
  }
  if(cache->sets != NULL){
    free(cache->sets);
  }
}

void printSummary(const Cache *cache) {
  printf("\n%s hits:%d misses:%d evictions:%d", cache->name, cache->hit_count,
         cache->miss_count, cache->eviction_count);
}
