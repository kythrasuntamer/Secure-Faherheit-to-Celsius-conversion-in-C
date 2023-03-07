#include <stdio.h>
#include "float-input.h"

int main() {
    float fahr, celsius;

    puts("Enter temperature in Fahrenheit: ");
    getFloatFromStdin(&fahr);

    celsius = (fahr- 32) * 5 / 9;

    printf("%3.0f %6.1f\n", fahr, celsius);

    return 0;
}
