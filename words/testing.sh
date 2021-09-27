#!/bin/bash
# Brian Yu
# 09/27/21
# Purpose: testing words.c - will test all cases that words.c is supposed to handle.
#"this is a test", "this is test two", and "This is test three" are the sentences that were put into stdin when the program
#is reading from stdin.

# zero arguments
./words

# one argument
./words lab

# two argument
./words lab lab

# '-' in between two arguments
./words lab - lab

#incorrect file name as first argument
./words lac

#incorrect file name as second argument
./words lab lac

#incorrect file name after dash
./words - lac

