#include <stdio.h> // Preprocessor directive

void squareElements(int *arr, int size);
// Main function - entry point of every C program
int main() {
    int numbers[5] = {2, 4, 6, 8, 10};
    int *ptr = numbers; // Pointer to the first element of the array
    printf("First element: %d\n", numbers[0]);  // Print the first element
    printf("The first element using pointer dereferencing: %d\n", *ptr);   // Print the first element using pointer dereferencing  
    printf("he third element using pointer arithmetic: %d\n", *(ptr + 2));  // Print the third element using pointer arithmetic  
    
    squareElements(ptr, 5);  // Call the function to square the elements of the array

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);  // Print the elements of the array
    }
    return 0; // Program ends successfully
}

void squareElements(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= *(arr + i);  // Square the element
    }
}
