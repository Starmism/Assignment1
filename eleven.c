#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * (15 points) A prime integer is any integer greater than 1 that can be divided evenly only by itself and 1.
 * The Sieve of Eratosthenes is a method of finding prime numbers. It works as follows:
 *      a) Create an array with all elements initialized to 1 (true).
 *          Array elements with prime in-dices will remain 1.
 *          All other array elements will eventually be set to zero.
 *      b) Starting with array index 2 (index 1 is not prime), every time an array element is found whose value
 *      is 1, loop through the remainder of the array and set to zero every element whose index is a multiple of the
 *      index for the element with value 1. For array index 2, all elements beyond 2 in the array that are multiples
 *      of 2 will be set to zero (indices 4, 6, 8, 10, and so on.). For array index 3, all elements beyond 3 in the
 *      array that are multiples of 3 will be set to zero (indices 6, 9, 12,15, and so on.).
 *
 * When this process is complete, the array elements that are still set to 1 indicate that the index is a prime number.
 * Write a program that uses an array of 1,000 elements to determine and print the prime numbers between 1 and 999.
 * Ignore element 0 of the array.
 */
int main() {
    bool sieve[1000];
    memset(sieve, true, 1000 * sizeof(bool));

    for (int i = 2; i * i <= 999; i++) {
        if (sieve[i] == true) {
            for (int j = 2 * i; j <= 999; j += i) {
                sieve[j] = false;
            }
        }
    }

    printf("List of primes from 2-1000:\n");

    for (int i = 2; i <= 999; i++) {
        if (sieve[i]) {
            printf("%d ", i);
        }

        if (i % 100 == 0) {
            printf("\n");
        }
    }

    return 0;
}