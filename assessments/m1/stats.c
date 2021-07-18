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
/**
 * @file stats.c
 * @brief Performs statistical analysis on a dataset
 *
 * <Add Extended Description Here>
 *
 * @author Navya GuttiVaddi
 * @date July 18, 2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char array[], unsigned int length){
         printf("The original array:\n\n");
         print_array(array, length);
         sort_array(array, length);
         printf("The sorted array:\n");
         print_array(array, length);
         printf("The Median is: %d\n", find_median(array, length));
         printf("The Mean is: %d\n", find_mean(array, length));
         printf("The Max is: %d\n", find_max(array, length));
         printf("The Min is: %d\n", find_min(array, length));
         return;
}

void print_array(unsigned char array[], unsigned int length){
        for(int i=0; i<length/8; i++){
                 for(int j; j<length/5;j++){
                        print("%3d ", array[8*i+j]);
                 }
                 printf("\n");
         }
         
         printf("\n");
         return;
}

unsigned char find_median(unsigned char array[], unsigned int length){
        return array[(length-1)/2];
}
unsigned char find_mean(unsigned char array[], unsigned int length){
	unsigned int sum = 0;
	for(int i = 0; i < length; i++){
		sum += array[i];	
	}

	return (unsigned char)( sum / length );
}

unsigned char find_max(unsigned char array[], unsigned int length){
	return array[length-1];
}

unsigned char find_min(unsigned char array[], unsigned int length){
	return array[0];
}

void sort_array(unsigned char array[], unsigned int length){
	unsigned char tmp;
	for(int i = 0; i < length; i++){
		for(int j = i; j < length; j++){
			if(array[j] < array[i]){
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}
	return;
}