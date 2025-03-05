#include <stdio.h> // Preprocessor directive

void incrementAge(int *ptr);
// Main function - entry point of every C program
int main() {
    int age = 21;
    int *ptr = &age;
    printf("Value of age: %d\n", age);          // Prints the value of num
    printf("Address of age: %p\n", &age);       // Prints the address of num
    printf("Pointer ptr stores: %p\n", ptr);    // Prints the address stored in ptr
    printf("Value pointed by ptr: %d\n", *ptr); // Dereferencing: accessing value using the pointer
    incrementAge(&age);
    printf("Updated age: %d\n", age); //Print age
    printf("Updated age (ptr): %d\n", *ptr); //Print age pointed to by pointer
    return 0; // Program ends successfully
}

void incrementAge(int *ptr) {
    (*ptr)++; //Increment age by 1
}
