#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "float-input.h"

int main() {
    float fahr, celsius;

    puts("Enter temperature in Fahrenheit: ");
    getFloatFromStdin(&fahr);

    while (isnan(fahr) || isinf(fahr)) {
        fprintf(stderr, "[ERROR]: Invalid input: please enter a valid temperature.\n");
        puts("Enter temperature in Fahrenheit: ");
        getFloatFromStdin(&fahr);
    }

    celsius = (fahr- 32) * 5 / 9;

    printf("%3.0f %6.10f\n", fahr, celsius);

    return 0;
}
