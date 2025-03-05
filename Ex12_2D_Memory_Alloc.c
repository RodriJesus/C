#include <stdio.h> // Preprocessor directive
#include <stdlib.h> // Required for malloc, calloc, realloc, free

void storeValues(int **matrix, int rows, int cols);
void printValuesMatrix(int **matrix, int rows, int cols);
int** allocateMemMatrix(int rows, int cols);

// Main function - entry point of every C program
int main() {
    int rows, cols;

    // Get dimensions from the user
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid number! Please enter a positive integer.\n");
        return 1;
    }
    printf("Enter number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid number! Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int **matrix = allocateMemMatrix(rows, cols);

    // Store values in the matrix
    storeValues(matrix, rows, cols);

    // Print the matrix
    printValuesMatrix(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the array of row pointers

    return 0;

}

void storeValues(int **matrix, int rows, int cols) {
    // Input values into the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                exit(1);
            }
        }
    }
}

void printValuesMatrix(int **matrix, int rows, int cols) {
    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** allocateMemMatrix(int rows, int cols) {
    // Allocate an array of row pointers
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            exit(1);
        }
    }
    return matrix; // Return the pointer to the array of row pointers
}



