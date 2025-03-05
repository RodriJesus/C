#include <stdio.h> // Preprocessor directive

struct MotorConfig { // Define a structure
    int speed;
    float voltage;
    char direction;
};

void updateAllMotors (struct MotorConfig *ptr, int size) {
    for (int i = 0; i < size; i++) {
        (ptr + i)->speed += 500;  // Update the speed
    }
}

void reverseDirections (struct MotorConfig *ptr, int size) { // Function to reverse the directions
    for (int i = 0; i < size; i++) {
        if ((ptr + i)->direction == 'R') {
            (ptr + i)->direction = 'F';
            printf("Reverse to F\n");
        } else {
            (ptr + i)->direction = 'R';
            printf("Reverse to R\n");
        }
    }
}
// Main function - entry point of every C program
int main() {
    struct MotorConfig motors[3] = { // Declare an array of structures
        {3000, 12.0, 'F'},
        {4500, 11.5, 'R'},
        {5000, 13.0, 'F'}
    };
    for (int i = 0; i < 3; i++) {  // Print the values of the structures
        printf("Speed(Before): %d\n", motors[i].speed);
        printf("Voltage(Before): %.1f\n", motors[i].voltage);
        printf("Direction(Before): %c\n", motors[i].direction);
    }

    //struct MotorConfig *ptr = &motor1;
    updateAllMotors(motors, 3);  // Increase the speed of all motors
    reverseDirections(motors, 3);  // Reverse the directions of all motors
    for (int i = 0; i < 3; i++) {  // Print the updated values
        printf("Speed(After): %d\n", motors[i].speed);
        printf("Voltage(After): %.1f\n", motors[i].voltage);
        printf("Direction(After): %c\n", motors[i].direction);
    }

    return 0; // Program ends successfully
}

