#include "layer.h"

layer create_layer(int num_neurons)
{
  layer lyr;
  lyr.num_neurons = -1;
  lyr.neuron = (struct neuron_t *)malloc(num_neurons * sizeof(struct neuron_t));

  return lyr;
}
