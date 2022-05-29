#ifndef BACKPROP_H
#define BACKPROP_H

#include "layer.h"

#define SUCCESS_INIT 0
#define ERR_INIT 1

#define SUCCESS_DINIT 0
#define ERR_DINIT 1

#define SUCCESS_INIT_WEIGHTS 0
#define ERR_INIT_WEIGHTS 1

#define SUCCESS_UPDATE_WEIGHTS 0

#define SUCCESS_CREATE_ARCHITECTURE 0
#define ERR_CREATE_ARCHITECTURE 0

int init(void);
int dinit(void);

int create_architecture(void);
int initialize_wights(void);
void input_data(int i);
void train(void);
void forward_prop(void);
void caculate_cost(int i);
void back_prop(void);
void updated_wights(void);
void get_inputs(void);
void get_outputs(void);
void test_nn(void);

int initialize_dummy_weights(void);

#endif
