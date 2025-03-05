#include <stdio.h> // Preprocessor directive

struct MotorConfig { // Define a structure
    int speed;
    float voltage;
    char direction;
};

void updateMotor (struct MotorConfig *str, int speed, char dir) {
    str->speed = speed;  // Update the speed
    str->direction = dir;  // Update the direction
}
// Main function - entry point of every C program
int main() {
    struct MotorConfig motor1 = {3800, 12.2, 'F'}; // Declare a structure variable
    printf("Speed: %d\n", motor1.speed);  // Print the speed
    printf("Voltage: %.1f\n", motor1.voltage);
    printf("Direction: %c\n", motor1.direction);
    
    struct MotorConfig *ptr = &motor1;  // Pointer to the structure variable
    updateMotor(ptr, 7000, 'R');  // Call the function to update the motor
    printf("Speed(Updated): %d\n", motor1.speed);  // Print the updated values
    printf("Direction(Updated): %c\n", motor1.direction);

    return 0; // Program ends successfully
}

