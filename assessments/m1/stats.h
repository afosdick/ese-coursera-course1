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
 * @brief Module 1 Peer-graded assigment header file.
 *
 * Contains function prototype and descriptions for the module 1 assignment.
 *
 * @author Jaeger17
 * @date 10/10/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief print all statistics.
 *
 * prints the statistics of an array including the minimum, maximum, mean, and
 * median.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 *
 */
void print_statistics(unsigned char *array, size_t sz);

/**
 * @brief print the contents of an unsigned char array given the correct size.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 */
void print_array(unsigned char *array, size_t sz);

/**
 * @brief find the median of a sorted unsigned character array given the correct
 * size.
 *
 * @note the array argument MUST be sorted for this to work properly.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 *
 * @return unsigned char
 */
unsigned char find_median(unsigned char *array, size_t sz);

/**
 * @brief find the mean of an unsigned character array given the correct size.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 */
unsigned char find_mean(unsigned char *array, size_t sz);

/**
 * @brief find the median of an unsigned character array given the correct size.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 *
 * @return unsigned char
 */
unsigned char find_maximum(unsigned char *array, size_t sz);

/**
 * @brief find the median of an unsigned character array given the correct size.
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 *
 * @return unsigned char
 */
unsigned char find_minimum(unsigned char *array, size_t sz);

/**
 * @brief Sort an unsgined character array given the correct size.
 *
 * Utilizes qsort to sort the array in O(n*log(n)).
 *
 * @param array (unsigned char *): a pointer to the start of an unsigned char
 * array.
 * @param sz (size_t): size of the array.
 */
void sort_array(unsigned char *array, size_t sz);

/**
 * @brief Compare function needed by qsort.
 *
 * @param a (const void *) pointer to the first char
 * @param b (const void *) pointer to the second char
 * @return unsigned char
 */
static int uchar_compare(const void *a, const void *b);

#endif /* __STATS_H__ */