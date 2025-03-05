#include <stdio.h> // Preprocessor directive
#define MOTOR_ON       (1 << 0)  // Bit 0
#define MOTOR_DIR      (1 << 1)  // Bit 1
#define SPEED_BOOST    (1 << 2)  // Bit 2
#define EMERGENCY_STOP (1 << 3)  // Bit 3

struct MotorConfig { // Define a structure
    unsigned char ControlRegister; // Bit 0 - Motor On/Off, Bit 1 Direction (1 - Forward), Bit 2 Speed Boost (1 - Boosted)
}; // Bit 3 Emergency Stop (1 - Stop), Bit 4-7 Unused

void print_binary(unsigned char num);

void setBit(unsigned char *reg, unsigned char mask);

void clearBit(unsigned char *reg, unsigned char mask);

void toggleBit(unsigned char *reg, unsigned char mask);

// Main function - entry point of every C program
int main() {
    struct MotorConfig motor = {0}; // Declare struct
    setBit(&motor.ControlRegister, MOTOR_ON); // Turn on the motor
    setBit(&motor.ControlRegister, MOTOR_DIR);  // Set the direction to forward
    setBit(&motor.ControlRegister, SPEED_BOOST); // Boost the speed
    print_binary(motor.ControlRegister); // Print the binary representation of the ControlRegister
    toggleBit(&motor.ControlRegister, MOTOR_DIR); // Toggle the direction
    print_binary(motor.ControlRegister); // Print the binary representation of the updated ControlRegister
    return 0; // Program ends successfully
}

void print_binary(unsigned char num) { // Function to print the binary representation of a number
    printf("The binary representation of %u is: ", num);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}
void setBit(unsigned char *reg, unsigned char mask) {
    *reg |= mask;
}

void clearBit(unsigned char *reg, unsigned char mask) {
    *reg &= ~mask;
}

void toggleBit(unsigned char *reg, unsigned char mask) {
    *reg ^= mask;
}
