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
 * @file stats.h 
 * @brief Header file for stats.c. Performs statistical anaylsis on a dataset
 *
 * <Add Extended Description Here>
 *
 * @author Navya GuttiVaddi
 * @date July 18, 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function that prints the statistics of an array including minimum, 
 * maximum, mean, and median.
 *
 * @param array The array containing the dataset of unsigned chars
 * @param length The length of the array
 *
 * @return NULL
 */
void print_statistics(unsigned char array[], unsigned int length);


/** 
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 *
 * @return NULL
 */
void print_array(unsigned char array[], unsigned int length);


/** 
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 *
 * @return median The median of the array
 */
unsigned char find_median(unsigned char array[], unsigned int length);


/** 
 * @brief Given an array of data and a length, returns the min value
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 *
 * @return median The min of the array
 */
unsigned char find_min(unsigned char array[], unsigned int length);


/** 
 * @brief Given an array of data and a length, returns the max value
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 *
 * @return median The max of the array
 */
unsigned char find_max(unsigned char array[], unsigned int length);


/** 
 * @brief Given an array of data and a length, returns the mean value
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 *
 * @return median The mean of the array
 */
unsigned char find_mean(unsigned char array[], unsigned int length);


/** 
 * @brief Sorts the array using selection sort
 *
 * Selection sort is used despite its O(n^2) runtime because it has a 
 * spatial complexity of O(1) and that is more important in this 
 * embedded system context (limited memory).
 *
 * @param array An array of unsigned chars
 * @param length The length of the array
 */
void sort_array(unsigned char array[], unsigned int length);

#endif /* __STATS_H__ */