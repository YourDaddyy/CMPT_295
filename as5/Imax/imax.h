#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "intrin.h"
#include "logger.h"

using namespace std;

void imaxSerial(int *values, int *output, int N) {
  int x = 0xffffffff;
  int index = 0;
  for (int i = 0; i < N; i++) {
    if (values[i] > x) {
      x = values[i];
      index = i;
    }
  }
  *output = index;
}

// implementation of imax using instrinsics
void imaxVector(int *values, int *output, int N) {
  // GLOBAL_MAX, GLOBAL_INDEX
  int max = values[0];
  int index = 0;

  __cs295_vec_int x_v;

  for (int i = 0; i < N; i += VLEN) {
    int width = VLEN;
    if(N - i < VLEN){
      width = N - i;
    }
    __cs295_mask maskAll = _cs295_init_ones(width);
    _cs295_vload_int(x_v, values + i, maskAll);

    for (int j = 0; j < VLEN; j++) {
      if(x_v.value[j] > max){
        index = i + j;
        max = x_v.value[j];
      }
    }
    values[0] = max;
    output[0] = index;
    // Compare and update GLOBAL_MAX AND GLOBAL_INDEX
    // Move onto next VLEN elements. Caution: n may not be multiple of VLEN
  }
}