/* Brian Yu
 * 09/25/2021
 * lab 2, words
 * Usages: 
 * "./words [filename]" will print each word in the file on a new line.
 * "./words" will print whatever sentence that is typed into standard input on a new line.
 * "./words [filename] - [filename]" will print each word of the first file on a new line, then '-' will switch into printing each word from 
 * standard input. To go to the next file, user types ctrl-D, which will then print all the words in the next file. 
 * Purpose: As specified above, this program will print each word in a file on a new line. 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


//function prototype
int readPrint (FILE *fp);

int main (int argc, char *argv[]){

    //handling case where there are no agruments being passed
    if (argc == 1){
        FILE *fp = stdin;
        readPrint(fp); //read and print from standard input
      }

    //loop through all the arguments
    for (int i=1; i < argc; i++) {

      //handling case with "-"
      if (strcmp(argv[i], "-") == 0){
        FILE *fp = stdin;
        readPrint(fp);
      }

      //handling case where the file is unreadable
      else if (fopen(argv[i], "r") == NULL){
        fprintf(stderr, "Unable to read file %d\n", i); //print to standard error
        exit(1); // non-zero exit code
      }

      //when the file does open
      else {
        FILE *fp = fopen(argv[i], "r");
        readPrint(fp);
        fclose (fp); //making sure to close any open files
      }
    }
    return 0;
}

//function to read and then print what is in fp
int readPrint (FILE *fp){
  char c;
  bool word = false; //boolean to prevent from random spaces in front of a word printing each (each space) as a new line

//when there are things to read
  while ((c = fgetc(fp)) != EOF){
    
    //if what is read is a word
    if (isalpha(c) != 0){
      printf("%c" , c);
      word = true; //because it is a word, switch the boolean to true
    }

    //just print a new line if it's not a word
    else {
      if (word){
        printf("\n");
      }
      word = false; //switch it back to false
    }
  }
  if (word){ //need it again after the while loop ends because the first word of the second file might start on the same line
  //as the last word of the first file
    printf("\n");
  }
  
  return 0;
}