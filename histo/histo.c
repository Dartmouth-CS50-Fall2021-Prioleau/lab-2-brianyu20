/* Brian Yu
9/27/2021
lab 2 - histo
Usage: './histo' will enter into the program. Program will run with any standard input of integers greater than or equal to 0. 
When pressed enter, standard output will update the user that the bin size has been increased. If one line of standard input has 
more than one number that increased the bin size, it will prompt the user the number of numbers that increased bin size. 
If there are no bin size update to be done, the program will incorporate numbers given by the users until Ctrl-D is pressed. When 
Ctrl-D is pressed, The histogram will print and exit program. 
Purpose: Program will create a consistent histogram of 16 bins, and will increase the size of the bins according to the number that
the user gives as input. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int histogram (int bins, int observed[], int range);

int main (int argc, char *argv[]){

    const int bins = 16; //always starting off with 16 bins.
    int observed[bins]; //keeping track of the number of observed integers in that bin
    int range = 1; //at first, the range for each bin is 1; there can only be one integer (ex: 3's in bin 3) in this bin, initially.

    //initializing each bin with 0 observances
    for (int x=0; x < (bins+1); x++){
        observed[x]=0;
    }

    histogram(bins, observed, range);


    return 0;
}

int histogram (int bins, int observed[], int range) {
    
    int i=0;
    
    //print initial state of the histogram
    printf("%d bins of size %d for range [0,%d)\n", bins, range, (bins*range));

    //when there's something to read from standard input
    while ((scanf("%d", &i)) && !feof(stdin)){
       
        //handling case where there needs to be an increase in bin size
        if (i >= (bins*range)){
            //multiply the size of the bin until the integer fits 
            
            while (i >= (bins*range)){
                range = (range*2);
                //print the modified bin status
                printf("%d bins of size %d for range [0,%d)\n", bins, range, (bins*range));
            
                //need to compress the bins everytime bin size in increased, so it stays in the while loop
                for (int j=0; j < bins; j++){
                    //handling the bottom half
                    if (j< (bins/2)){
                        observed[j] = observed[(j*2)] + observed[((j*2+1))];
                    }
                    //handling the top half
                    else{
                        observed[j] = 0;
                    }
                }             
            }
        }

        if (i >= 0) { //simple if statement to include all numbers (lab instruction excluded negative numbers), 
                        //especially those that increase bin size to increment values within the bin
            int m = 1; //creating a variable to address cases where bin size is greater than one

            //loop through all the bins
            for (int l=0; l < (bins); l++){
                //uniquely handling cases where the bin size hasn't increased
                if (range == 1){
                    if (i == l){
                        //increment the observed value
                        observed[l] = observed[l]+1;
                    }
                }
                // handling all other cases where bin size has increased
                else {
                    if ((l*range) <= i && ((m*range)-1) >= i) {
                        //increment the observed value
                        observed[l] = observed[l]+1;  
                    }
                } 
                m++; //incrementing the extra variable 
            }
        }  
    }

    //for loop to print the statements
    for (int y=0; y < (bins); y++){
            //first print the bin
            printf("[%6d : %6d] ", (y*range),(y*range)+(range-1));
            //enter for loop within that bin to print the asterisks
            for (int z=1; z < (observed[y]+1); z++){ //z starts at 1 because it shouldn't print an asterisk if there aren't any observed value
                printf("*");
            }
            printf("\n"); //go to new line after all the asterisks are printed
        }

    return 0;
}