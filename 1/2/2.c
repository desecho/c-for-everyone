/*
    Sine calculator
*/
#include<stdio.h>
#include<math.h>

int main(void) {
    double value;
    printf("Enter a value between 0 and 1 (non inclusive): ");
    scanf("%lf", &value);
    // Check that a value is between 0 and 1 (non inclusive)
    if (value <= 0 || value >=1) {
        printf("Invalid value. Value must be between 0 and 1 (non inclusive)\n");
        return 1;
    }
    printf("Sine is: %lf \n", sin(value));
    return 0;
}
