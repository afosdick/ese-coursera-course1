## Week 3 Assessment

### Question 1
*g2*  
 - Segment: Code
 - Sub-segment: const/rodata
 - Permissions: Read
 - Lifetime: Indefinite

How answer is derived:  
 - Run `make build PLATFORM=HOST`
 - Look at `c1m3.map` and look for `g2` for Segment and Sub-segment
 - Look at `msp432p401r.lds` for Permissions
 - Look at main.c for Lifetime

### Question 2
*g4*  
 - Segment: Data
 - Sub-segment: BSS
 - Permissions: Read-write
 - Lifetime: Program

### Question 3
*g5*  
 - Segment: Data
 - Sub-segment: Data
 - Permissions: Read-write
 - Lifetime: Program

### Question 4
*l1*  
 - Segment: Register
 - Sub-segment: Stack
 - Permissions: Read-write
 - Lifetime: Function/Block


### Question 5
*l3*  
 - Segment: Data
 - Sub-segment: Stack
 - Permissions: Read-write
 - Lifetime: Function/Block


### Question 6
*SOME_VALUE*  
 - Segment: Code
 - Sub-segment: const/rodata
 - Permissions: Read
 - Lifetime: Indefinite

### Question 7
*f2*  
 - Segment: Data
 - Sub-segment: BSS
 - Permissions: Read-write
 - Lifetime: Program

### Question 8
*"Hello World!"*  
 - Segment: Code
 - Sub-segment: Text
 - Permissions: Read
 - Lifetime:

### Question 9
*main()*  
 - Segment: Code
 - Sub-segment: Text
 - Permissions: Read
 - Lifetime: Indefinite


