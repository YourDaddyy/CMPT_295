#include "intrin.h"
#include "logger.h"
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

void ReluSerial(int *values, int *output, int N)
{
  for (int i = 0; i < N; i++)
  {
    int x = values[i];
    if (x < 0)
    {
      output[i] = 0;
    }
    else
    {
      output[i] = x;
    }
  }
}

// implementation of relu using instrinsics
void ReluVector(int *values, int *output, int N)
{
  // TODO
  // Create vector registers for processing
  __cs295_vec_int x_v;
  __cs295_vec_int result_v = _cs295_vset_int(0);

  __cs295_vec_int zeros = _cs295_vset_int(0);

  for (int i = 0; i < N; i += VLEN) {
   
    // Disable non zeros.
    // Find out lanes for which either X  are less 0.

    // Load VLEN elements from X; values from contiguous memory
    // Is x[i] == 0 ?

    __cs295_mask maskAll = _cs295_init_ones(VLEN);

    _cs295_vload_int(x_v, values + i, maskAll);  // x = values[i];
    __cs295_mask mask_x_zeros;
    _cs295_vlt_int(mask_x_zeros, x_v, zeros, maskAll);

    // Activate non-zero lanes
    __cs295_mask mask_nz = _cs295_mask_not(mask_x_zeros);

    // Multiply non-zero values
    _cs295_vmove_int(result_v, x_v, mask_nz);
    // _cs295_vmove_int(result_v, zeros, mask_x_zeros);

    // Write results back to memory
    _cs295_vstore_int(output + i, zeros, maskAll);
    _cs295_vstore_int(output + i, result_v, mask_nz);

  }
}