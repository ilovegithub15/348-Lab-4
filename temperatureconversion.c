#include <stdio.h>
//Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
//Categorization function
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature Category: Freezing.\nWeather Advisory: Stay indoors or wear a coat.");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature Category: Cold.\nWeather Advisory: Wear a jacket.");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature Category: Comfortable.\nWeather Advisory: You should feel comfortable.");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature Category: Hot.\nWeather Advisory: Make sure you stay hydrated.");
    } else {
        printf("Temperature Category: Extreme Heat.\nWeather Advisory: Stay inside or in shade wherever possible.");
    }
}
int main() {
    //Initializes values for later
    float temperature;
    float temperature2;
    int input_scale, target_scale;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);
    //Input validation, ends program if inputs are not valid.
    if (input_scale < 1 || input_scale > 3) {
        printf("Invalid input scale.");
        return 1;
    }
    if (target_scale < 1 || target_scale > 3) {
        printf("Invalid target scale.");
        return 1;
    }
    //Celsius type
    if (input_scale == 1) {
        if (target_scale == 2) {
            temperature2 = celsius_to_fahrenheit(temperature);
            printf("Converted temperature: %.2f Degrees Fahrenheit\n", temperature2);
            categorize_temperature(temperature);
        } else if (target_scale == 3) {
            temperature2 = celsius_to_kelvin(temperature);
            printf("Converted temperature: %.2f Kelvin\n", temperature2);
            categorize_temperature(temperature);
        } else {
            printf("No conversion needed. Temperature in Celsius: %.2f\n", temperature);
            categorize_temperature(temperature);
        }
    //Farenheit Type
    } else if (input_scale == 2) {
        if (target_scale == 1) {
            temperature2 = fahrenheit_to_celsius(temperature);
            printf("Converted temperature: %.2f Degrees Celsius\n", temperature2);
            categorize_temperature(fahrenheit_to_celsius(temperature));
        } else if (target_scale == 3) {
            temperature2 = fahrenheit_to_celsius(temperature);
            temperature2 = celsius_to_kelvin(temperature2);
            printf("Converted temperature: %.2f Kelvin\n", temperature2);
            categorize_temperature(fahrenheit_to_celsius(temperature));
        } else {
            printf("No conversion needed. Temperature in Fahrenheit: %.2f\n", temperature);
            categorize_temperature(fahrenheit_to_celsius(temperature));
        }
    //Kelvin Type
    } else if (input_scale == 3) {
        if (target_scale == 1) {
            temperature2= kelvin_to_celsius(temperature);
            printf("Converted temperature: %.2f Degrees Celsius\n", temperature2);
            categorize_temperature(kelvin_to_celsius(temperature));
        } else if (target_scale == 2) {
            temperature2 = kelvin_to_celsius(temperature);
            temperature2 = celsius_to_fahrenheit(temperature2);
            printf("Converted temperature: %.2f Degrees Fahrenheit\n", temperature2);
            categorize_temperature(kelvin_to_celsius(temperature));
        } else {
            printf("No conversion needed. Temperature in Kelvin: %.2f\n", temperature);
            categorize_temperature(kelvin_to_celsius(temperature));
        }
    }
    return 0;
}