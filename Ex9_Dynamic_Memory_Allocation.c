#include <stdio.h> // Preprocessor directive
#include <stdlib.h> // Required for malloc, calloc, realloc, free

void storeValues (float *arr, int n) {
    // Store values in the allocated memory
    for (int i = 0; i < n; i++) {
        float input;
        printf("Enter a float value: ");
        scanf("%f", &input);
        arr[i] = input; // Store the value in the allocated memory
    }
}

void printValues (float *arr, int n) {
    // Print the values stored in the allocated memory
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function - entry point of every C program
int main() {
    int num; // Variable to store the number of floats
    printf("Number of floats you want to store: ");
    scanf("%d", &num);

    // Allocate memory for n integers
    float *arr = (float *)calloc(num, sizeof(float));
    
    if (arr == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1; // Exit the program
    }

    storeValues(arr, num); // Call the function to store values in the allocated memory
    printValues(arr, num); // Call the function to print the values stored in the allocated memory

    // Free the allocated memory
    free(arr);

    return 0;
}

