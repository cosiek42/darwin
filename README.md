# Darwin Simulation

A program simulating the evolution of individuals in the environment. A console application aimed at introducing structured programming in C++. The source code is properly prepared to generate Doxygen documentation in Polish.

## Requirements

Before running the program, you need to create two text files - input and output. Both of these files represent some individuals in the form of chromosomes, where one line of the file represents to one person and a line contains several numbers. So the input file must contain several lines of numbers and the output file must be empty. The simulation result will fill the output file with individuals.

The program must be run via the command line (like CMD) and all parameters must be provided.

## Translated Help

```sh
Usage: Darwin.exe -i input -o output -w ratio -r ratio -p generations -k pairs

No arguments    Show help
-i input        Set the input file with population
-o output       Set the output file with population
-w ratio        Specifie the extinction rate. Ratio should be a number in the range [0,1].
-r ratio        Specifie the reproduction rate. Ratio should be a number in the range [0,1]
-p generations  Set the number of generations in the simulation. Generations should be a positive natural number.
-k pairs        Set the number of pairs of individuals selected for crossing. Pairs should be a positive natural number.
```

## Input file example

```sh
2 9 84 9 5 6 25 12
2 98 56 2 54
5 2
8 5 22 5 48 6 1 9 8 7 554 25 235 32
```
