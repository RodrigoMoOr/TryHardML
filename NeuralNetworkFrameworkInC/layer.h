#include "neuron.h"

typedef struct layer_t
{
  int num_neurons;
  struct neuron_t *neuron;
} layer;