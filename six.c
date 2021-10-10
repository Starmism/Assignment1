#include <stdio.h>
#include <stdlib.h>

/*
 * (10 points) Write a C-function program to read 10 elements from a user and store it in an array.
 * Parse the elements of the array to print the numbers that lie in range 7 ≤ number ≤ 10.
 */
int main() {
    char buffer[10];
    size_t successfulNums = 0;
    long current;
    long numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (successfulNums < 10) {

        printf("Insert number (%lu/10) > ", successfulNums + 1);
        fgets(buffer, 10, stdin);

        current = strtol(buffer, NULL, 10);

        if (current <= 0) {
            printf("Invalid format / too small!\n");
            continue;
        }

        numbers[successfulNums] = current;

        successfulNums++;
    }

    printf("Numbers that lie between 7 <= x <= 10:\n");
    for (int i = 0; i < successfulNums; i++) {

        if (numbers[i] >= 7 && numbers[i] <= 10) {
            // Don't print the commas on the last one
            if (i != 0) {
                printf(", ");
            }

            printf("%ld", numbers[i]);
        }
    }

    return 0;
}