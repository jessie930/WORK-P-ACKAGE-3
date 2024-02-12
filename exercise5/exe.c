#include <stdio.h> // Include the standard input/output library for handling input/output operations
#include <stdlib.h> // Include the standard library for general functions including memory allocation, process control, conversions, and others
#include <time.h> // Include the time library for time functions

#define MAX 10 // Define a macro MAX with value 10 to set the size of the array

void pointerNum (int *arrayP); // Declare a function that takes a pointer to an integer array as its parameter

int main(){ // The main function where execution starts

    int array[MAX]; // Declare an integer array of size MAX (10)
    int *arrayP = array; // Declare a pointer to an integer and initialize it with the address of the array

    srand(time(0)); // Seed the random number generator with the current time
    
    for(int i = 0; i < MAX; i++) { // Loop to fill the array with random numbers
        array[i] = rand() % 99 + 1; // Assign a random number between 1 and 99 to each element of the array
    }

    printf("The value of the address of the array (pointer) is: %p\n", arrayP); // Print the memory address of the array (pointer to the first element)
    printf("First integer in the array is (array[0]): %d\n", array[0]); // Print the first element of the array
    printf("The last integer in the array is: %d \n", array[MAX-1]); // Print the last element of the array
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int)); // Print the size of an integer in bytes
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array)); // Print the total size of the array in bytes

    pointerNum(arrayP); // Call the pointerNum function passing the pointer to the array as argument

    return 0; // Return 0 to indicate successful execution
}

void pointerNum (int *arrayP){ // Define the pointerNum function which takes a pointer to an integer array as its parameter
    for (int i = 0; i < MAX; i++){ // Loop through each element of the array
        printf("Value: %d - Value * 2: %d\n", arrayP[i], arrayP[i] * 2); // Print the current value and its double
    }
}
