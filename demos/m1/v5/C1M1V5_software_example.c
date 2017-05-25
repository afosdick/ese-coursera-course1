/**************************************************************************//**
 * @file C1M1V5_CProgram_example.c
 * @brief Example C programming File
 * 
 * @author <Add FirsName LastName>
 * @date 2016-4-4
 *
 * A simple C-Programming example that exhibits a handful of basic c-programming
 * features to show how to calculate some statistics on a set of numbers:
 *     -Average
 *     -Maximum
 *     -Minimum
 *     -Number Historgram
 *
 *    Note: This program is not meant to be compiled nor efficient, but rather
 *          provide a handful of c-programming examples and coding guidelines.
 *
 *****************************************************************************/
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

#define NULL (0)
#define NUMBER_SET_LENGTH (20)
#define HISTORGRAM_LENGTH (6)
 
/******************************************************************************
 * Function: find_average
 * Description:
 *     This function takes a set of numbers and performs finds the average of
 *     of the set.
 * Parameters:
 *     int * ptr: Pointer to a data set
 *     int count: Number of items in data set
 * Return: 
 *     Average of the numbers provided.
 *****************************************************************************/
int find_average(int * ptr, int count);
 
void main(){
  int i = 0;
  /* A set of numbers in the range of [0,5] */
  int numbers[NUMBER_SET_LENGTH] = {1, 4, 5, 1, 3,
                                    2, 3, 2, 2, 4,
                                    0, 4, 5, 3, 1,
                                    0, 3, 0, 5, 3};
                     
  /* Histogram Array */
  int histogram[HISTORGRAM_LENGTH] = {0, 0, 0, 0, 0, 0};
  int average;
  int max;
  int min;
  
  average = find_average(numbers, NUMBER_SET_LENGTH);  

  while ( i < NUMBER_SET_LENGTH ){
    if ( i == 0 ) {
      max = numbers[0];    // Must initialize to values in set, not zero
      min = numbers[0];    // Move to second item and start comparisons
    }
    
    if ( numbers[i] <= min){
      min = numbers[i];
    }
    else if ( numbers[i] >= max){
      max = numbers[i];
    }
    
    histogram[i]++;
    
    i++;
  }
  /* Routines can be added here for Printing Data */
}

int find_average(int * ptr, int count){
  int i;
  int average;
  if ( ptr == NULL){
    return 0;
  }
  
  if ( count <= 0 ) {
    count = 1;
  }
  
  for(i = 0; i < count; i++){
    average += *ptr;
    ptr++;
  }
 
  return (average / count);
}
