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
 * @file misc.h 
 * @brief This file is to be used for the c1m3 assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#ifndef __MISC_H__
#define __MISC_H__

#define N (10U)

/**
 * @brief Arbitrary funciton to quiz students on allocation
 * 
 * This function is a arbitrary function with arbitrary code in it. Your job
 * is to analyze the allocated memory. You need to worry about what the code
 * does as it is completely arbitrary.
 *
 * @param v6 Pointer to an interger type
 *
 * @return Randome integer value
 */
int func(int * f1);

#endif /* __MISC_H__ */

