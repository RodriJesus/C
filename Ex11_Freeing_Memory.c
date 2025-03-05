#include <stdio.h> // Preprocessor directive
#include <stdlib.h> // Required for malloc, calloc, realloc, free
#include <string.h> // Required for string functions

void storeValues (char **arr, int n);
void printValues (char **arr, int n);

// Main function - entry point of every C program
int main() {
    int num;
    printf("Enter the number of words: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid number! Please enter a positive integer.\n");
        return 1;
    }

    // Allocate an array of character pointers
    char **words = (char **)malloc(num * sizeof(char *));
    if (words == NULL) {
        printf("Memory allocation failed!\n");
        free(words);
        return 1;
    }

    storeValues(words, num); // Call the function to store values in the allocated memory
    printValues(words, num); // Call the function to print the values stored in the allocated memory

    // Free the allocated memory
    free(words);

    return 0;
}

void storeValues (char **arr, int n) {
    // Store values in the allocated memory
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char)); // Max 50 characters per word
        if (arr[i] == NULL) {
            printf("Memory allocation failed for word %d!\n", i);
            i--; 
            while (getchar() != '\n'); // Clear input buffer
        }
        printf("Enter word %d: ", i + 1);
        scanf("%s", arr[i]); // Read string input
    }
}

void printValues (char **arr, int n) {
    // Print the values stored in the allocated memory
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");
}



