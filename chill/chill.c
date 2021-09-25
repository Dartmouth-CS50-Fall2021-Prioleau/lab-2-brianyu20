/*Brian Yu
09/25/2021
lab 2
Usage: ./chill temperature velocity (temperature and velocity are optional)
Purpose: This program will calculate the wind chill for various temperatures and velocities. The user
may put up to  2 arguments (excluding the ./chill). */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void oneArgument (); //will be called in the main function to address the case where there are no additional arguments passed in.
void twoArgument (float temp); //same as above, when the user passes in the temperature
void threeArgument (float temp, float velocity); //same as above, when the user passes in the temperature and velocity
float calcWindChill (float temp, float velocity); // will be used in the above functions to calculate the wind chill
void printTable (float temp, float velocity);// will be called to print lines of windchills.


int main (int argc, char *argv[]) { 
    //when there is no additional function being called,
    if (argc == 1){
        //print the header
        printf("Temp    Wind    Chill \n");
        printf("____    ____    _____ \n");
        // call the appropriate function
        oneArgument();
    }

    //when the temperature is passed in
    if (argc == 2){
        // if the temperature is in the right range,
        if (atof(argv[1])<50 && atof(argv[1])>(-99)){
            //print the header
            printf("Temp    Wind    Chill \n");
            printf("____    ____    _____ \n");
            //call the appropriate function
            twoArgument(atof(argv[1]));
        }
        //if the temperature is not in the range, print error message and exit. 
        else{
            fprintf(stderr, "Valid Temperature Range is between -99 and 50\n");
            exit(1);
        }
        
    }

    //when the user passes in a temperature and a velocity
    if (argc == 3){
        //if both the temperature and velocity is in the right range, 
        if ((-99)< atof(argv[1]) && atof(argv[1]) < 50 && atof(argv[2])>= 0.5){
            printf("Temp    Wind    Chill \n");
            printf("____    ____    _____ \n");
            //call the appropriate functions
            threeArgument(atof(argv[1]), atof(argv[2]));
        }

        //if they are not in the range, either the temperature or the velocity is not in range. check sequentially.
        else{
            //seeing if temperature is too high
            if (atof(argv[1]) >= 50){
                fprintf(stderr, "Temperature must be lower than 50\n");
                exit(1);
            }
            //seeing if temperature is too low
            if (atof(argv[1]) <= -99){
                fprintf(stderr, "Temperature must be higher than -99\n");
                exit(1);
            }
            //seeing if velocity is too low
            if (atof(argv[2]) <= 0.5) {
                fprintf(stderr, "Velocity must be greater than 0.5 mph\n");
            }
        }
    }
    //handling the case where there are too many arguments
    if (argc > 3){
        fprintf(stderr, "Usage: ./chill temperature velocity\n");
        exit(1);
    }

    return 0;
}

//function to calculate the windchill when passed in a temperature and velocity 
float calcWindChill(float temp, float velocity) {
    float windChill;
    windChill = 35.74 + 0.6215*temp - 35.75*(pow(velocity,0.16)) + 0.4275*temp*(pow(velocity,0.16));
   
   return windChill;
}

//printing function
void printTable (float temp, float velocity){
    printf("%.2f\t%.2f\t%.2f\n", temp, velocity, calcWindChill(temp, velocity));
}

//nested for loop to print temperature in 10's and velocity in 5's
void oneArgument() {
    float i;
    float j;
    for (i = -10; i < 41; i = i+10) {
        for (j = 5; j < 16; j = j+5){
            printTable(i,j);
        }
    }

}

//for loop to print the velocity in 5's for one given temperature
void twoArgument(float temp){
    float i;
    for (i = 5; i < 16; i = i+5){
        printTable(temp, i);
    }

}

//function for specific temperature and specific velocity.
void threeArgument(float temp, float velocity){
    printTable(temp, velocity);
}
