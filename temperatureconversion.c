#include <stdio.h>
int main() {
    float temperature;
    int input_scale, target_scale;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    if (input_scale < 1 || input_scale > 3) {
        printf("Invalid input scale.");
        return 1;
    }
    if (target_scale < 1 || target_scale > 3) {
        printf("Invalid target scale.");
        return 1;
    }
    return 0;
    }