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

#include <stdio.h>

/* Include guard used, compilation will NOT fail */
#include "my_file.h"
#include "my_file.h"
#include "my_file.h"

/* No include guard so compilation will fail for redeclaring functions */
#include "my_set.h"
#include "my_set.h"
#include "my_set.h"

#define LENGTH (10)

/* A pretty boring main file */
int main(void){

  char arr[LENGTH];

  set(arr, LENGTH, 0xff);
  clear(arr, LENGTH);

  printf("Hello World!\n");  // Std-Library function call!

  return 0;
}

