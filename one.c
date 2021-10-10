#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * (5 points) Write a C program to read 10 positive numbers from the user and print the largest and the second-largest values.
 */
int main() {
    u_int8_t successfulNums = 0;
    double highest = 0;
    double secondHighest = 0;
    double current;
    char buffer[50];

    while (successfulNums < 10) {
        printf("Insert number (%d/10) >  ", successfulNums + 1);
        fgets(buffer, 50, stdin);

        current = strtod(buffer, NULL);

        if (current <= 0) {
            printf("Invalid format / too small!\n");
            continue;
        }

        if (current > highest) {
            secondHighest = highest;
            highest = current;
        } else if (current > secondHighest) {
            secondHighest = current;
        }

        successfulNums++;
    }

    printf("\nHighest value given: %.2f\n", highest);
    printf("Second-highest value given: %.2f\n", secondHighest);

    return 0;
}