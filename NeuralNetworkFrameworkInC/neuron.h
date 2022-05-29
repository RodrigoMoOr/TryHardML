typedef struct neuron_t
{
  float activate;
  float *out_weights;
  float bias;
  float z;

  float dactivate;
  float *dw;
  float dbias;
  float dz;
} neuron;
