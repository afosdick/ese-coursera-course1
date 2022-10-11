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
 * @brief Module 1 Peer-graded assigment source code.
 *
 * Implements stats.h, utilizing all functionality for C programming
 * proof-of-concept.
 *
 * @author Jaeger17
 * @date 10/10/2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int
main(void)
{

    unsigned char test[SIZE]
        = { 34, 201, 190, 154, 8,   194, 2,   6,   114, 88,  45,  76, 123, 87,
            25, 23,  200, 122, 150, 90,  92,  87,  177, 244, 201, 6,  12,  60,
            8,  2,   5,   67,  7,   87,  250, 230, 99,  3,   100, 90 };

    puts("Module 1 Submission - Stats\n");

    printf("%-10s", "array: ");
    // print the array content
    print_array(test, SIZE);

    // sort the array
    sort_array(test, SIZE);
    printf("%-10s", "sorted: ");
    print_array(test, SIZE);

    // print all
    print_statistics(test, SIZE);
}

void
print_statistics(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {
        // print the array min
        printf("%-10s%d\n", "min: ", find_minimum(array, sz));

        // print the array max
        printf("%-10s%d\n", "max: ", find_maximum(array, sz));

        // print the array median
        printf("%-10s%d\n", "median: ", find_median(array, sz));

        // print the array average
        printf("%-10s%d\n", "mean: ", find_mean(array, sz));
    }
}

void
print_array(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {
        for (size_t i = 0; i < sz; i++)
        {
            printf("%d ", array[i]);
        }

        // print a newline after looping.
        puts("");
    }
}

unsigned char
find_median(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {

        double median = 0;
        size_t middle
            = (sz / 2) - 1; // subtract 1 because we have a 0 indexed array

        // if the number is even, the median is the average of the two middle
        // points
        if (sz % 2 == 0)
        {
            int medians_added = array[middle] + array[middle + 1];
            median               = medians_added / 2;
        }
        // if the count is odd, it is the middle data point in the array
        else
        {
            median = array[middle];
        }

        return median;
    }
    else
    {
        return 0;
    }
}

unsigned char
find_mean(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {
        // store the total in an unsigned int since the total can elapse
        // the storage alotment for an unsigned char.
        unsigned int total = 0;

        for (size_t i = 0; i < sz; i++)
        {
            total += array[i];
        }

        return total / sz;
    }
    else
    {
        return 0;
    }
}

unsigned char
find_maximum(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {
        unsigned char max = array[0];

        // start at 1 because we already assign min to array[0]
        for (size_t i = 1; i < sz; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }

        return max;
    }
    else
    {
        return 0;
    }
}

unsigned char
find_minimum(unsigned char *array, size_t sz)
{
    if (NULL != array)
    {
        unsigned char min = array[0];

        // start at 1 because we already assign min to array[0]
        for (size_t i = 1; i < sz; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }

        return min;
    }
    else
    {
        return 0;
    }
}

void
sort_array(unsigned char *array, size_t sz)
{
    qsort(array, sz, sizeof(unsigned char), uchar_compare);
}

static int
uchar_compare(const void *a, const void *b)
{
    // convert void pointer to unsigned char pointer and dereference for
    // comparison
    unsigned char uchar1 = *(unsigned char *)a;
    unsigned char uchar2 = *(unsigned char *)b;

    // return the result of this logical comparison arithmetic
    if (uchar1 == uchar2)
    {
        return 0;
    }
    else if (uchar1 > uchar2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}