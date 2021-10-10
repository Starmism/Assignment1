#include <stdio.h>
#include <string.h>
#include <limits.h>

void selectionSort(int initial[], size_t size, int output[]);

/*
 * (15 points) A selection sort algorithm for a one-dimensional array has the following steps:
 *      a) The smallest value in the array is found.
 *      b) It is swapped with the value in the first position of the array.
 *      c) The above steps are repeated for the rest of the array starting at
 *         the second position and advancing each time. Eventually the entire
 *         array is divided into two parts: the sub-array of items already sorted
 *         which is built up from left to right and is found at the beginning, and
 *         the sub-array of items remaining to be sorted, occupying the remainder
 *         of the array.
 *
 *    Write a C program that sorts an array of 10 integers using this algorithm.
 */
int main() {
    int numsToBeSorted[10] = {
            10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    printf("Unsorted: ");
    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", numsToBeSorted[i]);
    }

    int sortedNums[10];
    selectionSort(numsToBeSorted, 10, sortedNums);

    printf("\nSorted: ");
    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", sortedNums[i]);
    }

    return 0;
}

void selectionSort(int initial[], size_t size, int output[]) {
    memcpy(output, initial, size * sizeof(int));

    for (int i = 0; i < size; i++) {
        int min = INT_MAX;
        int indMin = -1;

        for (int j = i; j < size; j++) {
            if (output[j] < min) {
                min = output[j];
                indMin = j;
            }
        }

        int old = output[i];
        output[i] = output[indMin];
        output[indMin] = old;
    }
}