#!/bin/bash

#lab 2, testing histo
#09/28/2021
#Purpose: program to test histo. Tests extreme cases as well as normal cases that should work. 


#testing case before bin size increases
echo 1 2 2 3 3 3 15 | ./histo

#testing case where bin size increases
echo 1 2 2 3 3 3 19 | ./histo


#testing case where bin size increases multiple times
echo 1 2 2 3 3 3 19 37 | ./histo


#testing case where input requires multiple iterations of increasing bin size
echo 150 | ./histo
