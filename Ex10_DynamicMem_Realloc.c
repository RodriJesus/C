#include <stdio.h> // Preprocessor directive
#include <stdlib.h> // Required for malloc, calloc, realloc, free

void storeValues (float *arr, int n);
void printValues (float *arr, int n);
void ResizeArray(float **arr, int num, int newSize);

// Main function - entry point of every C program
int main() {
    int num; // Variable to store the number of floats
    printf("Number of floats you want to store: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid number! Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for n integers
    float *arr = (float *)calloc(num, sizeof(float));
    
    if (arr == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        free(arr);
        return 1; // Exit the program
    }

    storeValues(arr, num); // Call the function to store values in the allocated memory
    printValues(arr, num); // Call the function to print the values stored in the allocated memory

    // Asking if the user wants to expand the array
    int newSize;
    printf("Enter the new size for the array: ");
    if (scanf("%d", &newSize) != 1 || newSize <= 0) {
        printf("Invalid size! Keeping original size.\n");
    } else if (newSize != num) { // Handle both shrinking and expanding
        ResizeArray(&arr, num, newSize);
        num = newSize;
    }

    printValues(arr, newSize); // Call the function to print the values stored in the allocated memory

    // Free the allocated memory
    free(arr);

    return 0;
}

void storeValues (float *arr, int n) {
    // Store values in the allocated memory
    for (int i = 0; i < n; i++) {
        printf("Enter a float value: ");
        if (scanf("%f", &arr[i]) != 1) {
            printf("Invalid input. Please enter a valid float.\n");
            i--; 
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

void printValues (float *arr, int n) {
    // Print the values stored in the allocated memory
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void ResizeArray(float **arr, int num, int newSize) {
    float *temp = (float *)realloc(*arr, newSize * sizeof(float));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(*arr); // Free the original array
        exit(1); // Exit the program
    }
    *arr = temp; // Update the pointer in main

    if (newSize > num) {
        printf("Enter additional %d values:\n", newSize - num);
        storeValues(*arr + num, newSize - num);
    } else {
        printf("Array shrunk to %d elements. Excess elements are discarded.\n", newSize);
    }
}

