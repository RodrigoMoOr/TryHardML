#include "backpropagation.h"
#include "layer.h"
#include "neuron.h"

layer *lyr = NULL;
int num_layers;
int *num_neurons;
float alpha;
float *cost;
float full_cost;
float **input;
float **outputs;
int num_training_samples;
int n = 1;

int main(void)
{
  int i;

  srand(time(0));

  printf("Enter the number of layers in Neural Networks:\n");
  scanf("%d", &num_layers);

  num_neurons = (int *)malloc(num_layers * sizeof(int));
  memset(num_neurons, 0, num_layers * sizeof(int));

  for (i = 0; i < num_layers; i++)
  {
    printf("Enter number of neurons for layer [%d]: \n", i + 1);
    scanf("%d", &num_neurons[i]);
  }

  printf("\n");

  if (init() != SUCCESS_INIT)
  {
    printf("Error initializing \n");
    exit(0);
  }

  printf("Enter learning rate: \n");
  scanf("%f", &alpha);
  printf("\n");

  printf("Enter the number of training samples: \n");
  scanf("%d", &num_training_samples);
  printf("\n");

  input = (float **)malloc(num_training_samples * sizeof(float *));
  for (i = 0; i < num_training_samples; i++)
  {
    input[i] = (float *)malloc(num_neurons[0] * sizeof(float));
  }

  outputs = (float **)malloc(num_training_samples * sizeof(float *));
  for (i = 0; i < num_training_samples; i++)
  {
    outputs[i] = (float *)malloc(num_neurons[num_layers - 1] * sizeof(float));
  }

  cost = (float *)malloc(num_neurons[num_layers - 1] * sizeof(float));
  memset(cost, 0, num_neurons[num_layers - 1] * sizeof(float));

  if (dinit() != SUCCESS_DINIT)
  {
    printf("Error in Dinitialization...\n");
  }

  return 0;
}

int init()
{
  if (create_architecture() != SUCCESS_CREATE_ARCHITECTURE)
  {
    printf("Error creating Neural Network Architecture...\n");
    return ERR_INIT;
  }

  printf("Neural Network Created Successfully...\n\n");
  return SUCCESS_INIT;
}

void get_inputs()
{
  int i, j;

  for (i = 0; i < num_training_samples; i++)
  {
    printf("Enter inputs for training example [%d]:\n", i);

    for (j = 0; j < num_neurons[0]; j++)
    {
      scanf("%f", &input[i][j]);
    }
    printf("\n");
  }
}

void get_outputs()
{
  int i, j;

  for (i = 0; i < num_training_samples; i++)
  {
    for (j = 0; j < num_neurons[num_layers - 1]; j++)
    {
      printf("Enter the Desired Outputs (Labels) for training example[%d]: \n", i);
      scanf("%f", &outputs[i][j]);
      printf("\n");
    }
  }
}
