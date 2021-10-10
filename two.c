#include <stdio.h>

/*
 * (15 points) Write a C program using control structures to print the following sequences:
 * i)  ******
 *     *****
 *     ****
 *     ***
 *     **
 *     *
 *
 * ii)     *
 *        ***
 *       *****
 *      *******
 *     *********
 *
 * iii)  * * * * *
 *       *       *
 *       *       *
 *       *       *
 *       * * * * *
 */
int main() {

    for (int i = 6; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }

    //////////////////////////////////////
    printf("\n\n");
    /////////////////////////////////////

    for (int i = 1; i < 10; i += 2) {
       for (int j = 1; j < (11 - i) / 2; j++) {
           printf(" ");
       }

       for (int k = 1; k <= i; k++) {
           printf("*");
       }
       printf("\n");
    }

    //////////////////////////////////////
    printf("\n\n");
    /////////////////////////////////////

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 || i == 4) {
                printf("* ");
            } else if (j == 0 || j == 4) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}