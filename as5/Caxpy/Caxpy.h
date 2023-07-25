#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "intrin.h"
#include "logger.h"

using namespace std;

void CAXPYSerial(int N, int cond[], int a, int X[], int Y[]) {
  int i;
  for (i = 0; i < N; i++) {
    if (cond[i]) Y[i] = a * X[i] + Y[i];
  }
}

// implementation of relu using instrinsics
void CAXPYVector(int N, int cond[], int a, int X[], int Y[]) {
 // TODO

 int width =  VLEN;
 // Create vector registers for processing
  __cs295_vec_int x_v, y_v, condit;
  __cs295_vec_int result_v;

  __cs295_vec_int zeros = _cs295_vset_int(0);

  for (int i = 0; i < N; i += VLEN) {
   
    // Disable non zeros.
    // Find out lanes for which either X or Y are 0.

    // Load VLEN elements from X; values from contiguous memory
    // Is x[i] == 0 ?

    __cs295_mask maskAll = _cs295_init_ones(width);

    __cs295_mask mask_condit;

    _cs295_vload_int(x_v, X + i, maskAll);  // x = values[i];
    _cs295_vload_int(y_v, Y + i, maskAll);
    _cs295_vload_int(condit, cond + i, maskAll);

    _cs295_veq_int(mask_condit, condit, zeros, maskAll);
    mask_condit = _cs295_mask_not(mask_condit);

    _cs295_vset_int(result_v, a, maskAll);
    _cs295_vmult_int(x_v, x_v, result_v, mask_condit);
    _cs295_vadd_int(y_v, x_v, y_v, mask_condit);

    // Write results back to memory
    _cs295_vstore_int(Y + i, y_v, mask_condit);
  }
}