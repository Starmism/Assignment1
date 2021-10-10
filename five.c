#include <stdio.h>
#include <stdlib.h>

/*
 * (10 points) Write a C program that searches for an integer (provided by the user) in the following
 * array of elements and prints the index (sub-script) of the number.
 * If the number does not exist in the array print -1.
 *
 * A = {1, 3, 4, 5, 9, 10, 11, 12, 13, 15, 16, 17, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
 *      30, 32, 33, 34, 35, 37, 38, 39, 40, 42, 43, 44, 45, 46, 47, 48, 49, 50}.
 *
 * Sample Outputs:
 *      Please enter a number between 1 and 50: 5
 *          The index of the number 5 is 3P
 *      Please enter a number between 1 and 50: 2
 *          The index of the number 2 is -1
 */
int main() {
    int A[] = {1, 3, 4, 5, 9, 10, 11, 12, 13, 15, 16, 17, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
               30, 32, 33, 34, 35, 37, 38, 39, 40, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    size_t size = 40;

    printf("Please enter a number between 1 and 50: ");
    char buffer[5];
    fgets(buffer, 5, stdin);

    long value = strtol(buffer, NULL, 10);

    int index = 0;
    while (index <= size && A[index] != value) {
        index++;
    }

    if (index > size) {
        index = -1;
    }

    printf("The index of the number %ld is %d\n", value, index);

    return 0;
}