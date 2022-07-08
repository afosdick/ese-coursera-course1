
#include <stdint.h>
#include <stddef.h>

#include "platform.h"
#include "stats.h"
#include "course1.h"
#include "data.h"
#include "memory.h"

#define BASE_10 (10)
#define BASE_16 (16)

uint8_t int_to_hex(int32_t digit) {
    switch (digit) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9: {
            return digit + 48;
            break;
        }
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15: {
            return digit + 55;
            break;
        }
        default:
            return '0';
    }
}

int32_t hex_to_int(uint8_t hex) {
    switch (hex) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            return hex - 48;
            break;
        }
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F': {
            return hex - 55;
            break;
        }
        default:
            return 0;
    }
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    int isNegative = data < 0;
    int32_t positive_data = data * (isNegative ? -1 : 1);

    int i = 0;
    if (isNegative) {
        *ptr = '-';
        i++;
    }
    int32_t remainder = positive_data;
    int digit_place = 0;
    int32_t current_digit_value = 1;
    while (remainder > 0) {
        int32_t next_digit_value = current_digit_value * base;
        remainder -= remainder % next_digit_value;
        digit_place++;
        current_digit_value = next_digit_value;
    }
    digit_place--;
    current_digit_value /= base;
    remainder = positive_data;
    while(digit_place >= 0) {
        int digit = remainder / current_digit_value;
        *(ptr + i) = int_to_hex(digit);
        remainder = remainder % current_digit_value;
        i++;
        digit_place--;
        current_digit_value /= base;
    }
    *(ptr + i) = '\0';
    return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int isNegative = (*(ptr) == '-');
    int i = 0;
    while (*(ptr + i) != '\0') {
        i++;
    }
    i--;
    uint32_t digit_value = 1;
    while (i >= 0 && (*(ptr+i) != '-')) {
        result += digit_value * hex_to_int(*(ptr+i));
        digit_value *= base;
        i--;
    }
    return result * (isNegative ? -1 : 1);
}
