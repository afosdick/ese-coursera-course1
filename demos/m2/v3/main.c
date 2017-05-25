/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

#include "my_file.h"

/* Uncomment the pragma to see the preprocessor exit as a failure */
//#pragma GCC poison printf


/* This is a compile time switch that includes different header files */
/* based on a command line define. This is just ONE way to implement this */
#if defined(KL25Z) && ! defined(MSP)
#include "kl25z.h"
#elif defined(MSP) && ! defined(KL25Z)
#include "msp.h"
#else
#error "Please specify only a single platform, -DKL25Z or -DMSP"
#endif

/* A pretty boring main file */
int main(void){

  char arr[LENGTH];

  clear(arr, LENGTH);

#ifdef KL25Z
  kl25z_platform_print();
#endif 
#ifdef MSP
  msp_platform_print();
#endif

  return 0;
}

