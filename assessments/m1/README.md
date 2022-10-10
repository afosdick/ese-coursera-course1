# Stats
Stats is the module 1 submission for the Coursera course, Introduction to Embedded Systems Software and Development Environments - University of Colorado by Alex Fosdick. Stats displays simple information about an unsigned char array such as the array's minimum number, maximum number, median and mean. The source also provides a `qsort` implementation that sorts an unsigned char array. 

## Build
Once you have the source files cloned or unzipped, you can either utilize the provided `Makefile` or `gcc` command. See below for sample commands and expected output.

### Makefile
#### `Make`
```bash
$ make
gcc --std=c99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -fno-common  stats.c -o stats
```
#### `Debug`
```bash
$ make debug
gcc --std=c99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -fno-common  -g3 stats.c -o stats
```

#### `Profile`
```bash
$ make profile
gcc --std=c99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -fno-common  -pg stats.c -o stats
```

#### `Clean`
```bash
$ make clean
rm -f stats
```

### GCC
```bash
$ gcc -o stats stats.c
```

## Run
After successfully building the program:

```bash
$ ./stats
```

Expected output

```bash
Module 1 Submission - Stats

array:    34 201 190 154 8 194 2 6 114 88 45 76 123 87 25 23 200 122 150 90 92 87 177 244 201 6 12 60 8 2 5 67 7 87 250 230 99 3 100 90 
sorted:   2 2 3 5 6 6 7 8 8 12 23 25 34 45 60 67 76 87 87 87 88 90 90 92 99 100 114 122 123 150 154 177 190 194 200 201 201 230 244 250 
min:      2
max:      250
median:   87.5000
mean:     93.9750
```

## Bugs
No known bugs. Please report issues to `jaeger17@protonmail.com`
