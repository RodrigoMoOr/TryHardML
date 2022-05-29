#include "neuron.h"

neuron create_neuron(int num_weights)
{
  neuron n;

  n.activate = 0.0;
  n.out_weights = (float *)malloc(num_weights * sizeof(float));
  n.bias = 0.0;
  n.z = 0.0;

  n.dactivate = 0.0;
  n.dw = (float *)malloc(num_weights * sizeof(float));
  n.dbias = 0.0;
  n.dz = 0.0;

  return n;
}