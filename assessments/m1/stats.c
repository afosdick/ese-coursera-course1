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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void sort_array(char* arr, int length);

void swap(unsigned char* a, unsigned char* b) {
  unsigned char t = *a;
  *a = *b;
  *b = t;
}

void print_array(unsigned char* arr, int length) {
  for (int i = 0; i < length; i++) {
    if (i == 0) {
      printf("%d", arr[i]);
      continue;
    }
    printf(", %d", arr[i]);
  }
  printf("\n");
}

unsigned char find_median(unsigned char* arr, int length) {
  unsigned char* arr_copy = (unsigned char *) malloc(length * sizeof(char));
  memcpy(arr_copy, arr, length * sizeof(char));
  sort_array(arr_copy, length);
  if (length %2 == 1) {
    return arr_copy[length / 2];
  }
  return (arr_copy[length / 2 - 1] + arr_copy[length / 2]) / 2;
}

unsigned char find_mean(unsigned char* arr, int length) {
  long sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  return sum / length;
}

unsigned char find_maximum(unsigned char* arr, int length) {
  unsigned char maximum = -1;
  if (length == 0) {
    return -1;
  }
  maximum = arr[0];
  for (int i = 0; i < length; i++) {
    maximum = maximum > arr[i] ? maximum: arr[i];
  }
  return maximum;
}

unsigned char find_minimum(unsigned char* arr, int length) {
  unsigned char minimum = -1;
  if (length == 0) {
    return -1;
  }
  minimum = arr[0];
  for (int i = 0; i < length; i++) {
    minimum = minimum < arr[i] ? minimum: arr[i];
  }
  return minimum;
}

void quicksort(unsigned char* arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = arr[left];
  int left_it = left+1;
  int right_it = right;
  while (left_it < right_it) {
    if (arr[left_it] < pivot && arr[right_it] > pivot) {
      swap(&(arr[left_it]), &(arr[right_it]));
      continue;
    }
    if (arr[right_it] <= pivot) {
      right_it--;
      continue;
    }
    if (arr[left_it] >= pivot) {
      left_it++;
      continue;
    }
  }

  int pivot_index = left;
  if (arr[left_it] > pivot) {
    swap(&(arr[left]), &(arr[left_it]));
    pivot_index = left_it;
  }
  quicksort(arr, left, pivot_index - 1);
  quicksort(arr, pivot_index + 1, right);
}

void sort_array(char* arr, int length) {
  quicksort(arr, 0, length - 1);
  return;
}

void print_statistics(char* arr, int length) {
  printf("Median: %d\n", find_median(arr, SIZE));
  printf("Mean: %d\n", find_mean(arr, SIZE));
  printf("Maximum: %d\n", find_maximum(arr, SIZE));
  printf("Minimum: %d\n", find_minimum(arr, SIZE));
}

void main(int argc, char* argv[]) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  printf("Program name %s\n", argv[0]);
  if (argc > 2) {
    printf("Too many arguments\n");
    return;
  }
  char* command = "statistics";
  if (argc == 2) {
    command = argv[1];
  }
  if (strcmp("statistics", command) == 0) {
    print_statistics(test, SIZE);
    return;
  }
  if (strcmp("sort", command) == 0) {
    print_array(test, SIZE);
    sort_array(test, SIZE);
    print_array(test, SIZE);
    return;
  }

}

/* Add other Implementation File Code Here */
