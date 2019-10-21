# explicit-algorithm-volterra

Here we perform some mathematicial calculation for for our volterra explicit algorithm paper

- [volterra-explicit](https://arxiv.org/abs/1908.02862)

Work in progress...

The directory **approxh** contains the class, source files and driver that implement Theorem 2.7 of the paper. T
Function 

The `testhhs.cpp` execute `hhsum.cpp`, and the dependency is `hhsum.hpp`.

## To compile

1. **Method 1**: Assuming you are on linux and have downloaded/cloned the repository, open **approxh** from your terminal, to get it up and running you just need to execute `make`. Then run `/.hhsum`. 

To clean up all executable, execute `make clean`.

2. **Method 2**: If you just want a quick run of my program that computes formula (2.26). Open the directory from terminal, simply compile by executing `g++ -o test hhsum.cpp`.
