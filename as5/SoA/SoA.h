#include "intrin.h"
#include "logger.h"
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int SoASerial(int *values, int N)
{
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += values[i];
  }

  return sum;
}
// Assume N % VLEN == 0
// Assume VLEN is a power of 2
int SoAVector(int *values, int N) {
  int sum = 0;
  __cs295_vec_int x_v;

  for (int i = 0; i < N; i += VLEN) {

    __cs295_mask maskAll = _cs295_init_ones(VLEN);

    _cs295_vload_int(x_v, values + i, maskAll); 
    
    for(int j = VLEN; j > 1; j /= 2){
      _cs295_hadd_int(x_v, x_v);
      _cs295_interleave_int(x_v, x_v);
    }
    sum += x_v.value[0];
  }
  return sum;
}
