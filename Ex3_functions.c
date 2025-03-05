#include <stdio.h> // Preprocessor directive

void checkAge(int age);
void countUp(int limit);
void countDown(int start);
// Main function - entry point of every C program
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    checkAge(age);
    countUp(age);
    countDown(age); 
    
    return 0; // Program ends successfully
}

void checkAge(int age) {
    if (age < 18) {
        printf("You are a minor.\n");
    } else if (age >= 18 && age <= 64) {
        printf("You are an adult.\n");
    } else {
        printf("You are a senior citizen.\n");
    }
}

void countUp(int limit) {
    for (int i = 1; i <= limit; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void countDown(int start) {
    while (start > 0) {
        printf("%d ", start);
        start--;
    }
    printf("\n");
}