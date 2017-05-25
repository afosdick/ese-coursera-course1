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
#include "my_memory.h"

extern char memory[MAX_LENGTH];

/* A pretty boring main file */
int main(void){

  clear_all(memory, MAX_LENGTH);
  set_value(memory, 0xAA, 0);
  set_value(memory, 0xFF, 1);

  return 0;
}

