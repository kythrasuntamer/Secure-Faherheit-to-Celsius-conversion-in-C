#ifndef FLOAT_INPUT_H
#define FLOAT_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  // Add this header to access errno

#define MAX_DIGITS 12

static inline void ClearInputBuffer() 
{
    char c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void getFloatFromStdin(float *inputFloat)
{
    char *inputBuffer = malloc(sizeof(char) * MAX_DIGITS);
    memset(inputBuffer, 0, MAX_DIGITS);
    char *input = NULL;
    while (input == NULL) {
        input = fgets(inputBuffer, MAX_DIGITS, stdin);

        if (inputBuffer[strlen(inputBuffer) - 1] != '\n') {
            fprintf(stderr, "[ERROR]: Too many characters: max input is %d chars.\n", MAX_DIGITS);
            ClearInputBuffer();
            input = NULL;
            continue;
        }

        errno = 0;
        char *endptr = NULL;
        *inputFloat = strtof(input, &endptr);

        if (input == endptr) {
            input[strcspn(input, "\n")] = 0;
            printf("Invalid input: no float found in %s.\n", input);
            input = NULL;
        }
        if (errno != 0) {
            fprintf(stderr, "[ERROR]: That doesn't look like a float.\n");
            input = NULL;
        }
    }
    free(inputBuffer);
}

#endif
