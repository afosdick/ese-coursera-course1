## Installation
### Install gcc-arm-none-eabi
```
sudo apt-get update
sudo apt-get install gcc-arm-none-eabi
```
Note that the command is `arm-none-eabi-gcc`, different from the package name

## Usage
 - `make build PLATFORM=HOST` - Building the executable file
 - `./c1m2.out` - Run the executable file
 - `make [file].o PLATFORM=HOST` - Build object file
 - `make [file].d PLATFORM=HOST` - Build dependency file
 - `make [file].asm PLATFORM=HOST` - Build assembly file
 - `make [file].i PLATFORM=HOST` - Build preprocessed file
 - `make clean PLATFORM=HOST` - Clean up

And the equivalent for MSP432 target:
 - `make build PLATFORM=MSP432`
 - `./c1m2.out`
 - `make [file].o PLATFORM=MSP432`
 - `make [file].d PLATFORM=MSP432`
 - `make [file].asm PLATFORM=MSP432`
 - `make [file].i PLATFORM=MSP432`
 - `make clean PLATFORM=MSP432`

## Unsolved Problems
Unclear instruction on using `objdump` for assembly files
