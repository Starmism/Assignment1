#include <stdio.h>

int sumDigits(int digits);

/*
 * (10 points) Write a C program that contains a function, called SumDigits that
 * accepts an integer value and returns the sum of the individual digits.
 *
 * Example: SumDigits(1232) should return 8
 */
int main() {
    printf("%d\n", sumDigits(1232));
    printf("%d\n", sumDigits(9999));

    return 0;
}

int sumDigits(int digits) {
    int sum = 0;

    while (digits != 0) {
        sum += digits % 10;
        digits /= 10;
    }

    return sum;
}