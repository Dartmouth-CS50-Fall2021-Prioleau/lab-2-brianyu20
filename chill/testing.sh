#!/bin/bash
# Brian Yu
# 09/25/21
# Purpose: ----

# zero arguments
./chill  

# one argument
./chill 32  

# two arguments
./chill 32 7  

# one argument out of range
./chill 100  

# two arguments, first argument out of range
./chill 100 7  

# two arguments, second argument out of range
./chill 32 0.2

