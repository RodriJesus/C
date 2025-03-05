#include <stdio.h> // Preprocessor directive

// Main function - entry point of every C program
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 18) {
        printf("You are a minor.\n");
    } else if (age >= 18 && age <= 64) {
        printf("You are an adult.\n");
    } else {
        printf("You are a senior citizen.\n");
    }
    for (int i = 1; i <= age; i++) {
        printf("%d ", i);
    }
    printf("\n");
    int a = age;
    while (a > 0) {
        printf("%d ", a);
        a--;
    }
    return 0; // Program ends successfully
}