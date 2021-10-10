#include <stdio.h>

/*
 * (15 points) Use a two-dimensional array to solve the following problem.
 * A company has four salespeople (1 to 4) who sell five different products (1 to 5).
 * Once a day, each salesperson passes in a slip for each different type of product sold.
 * Each slip contains:
 *      a) The salesperson number
 *      b) The product number
 *      c) The total dollar value of that product sold that day
 *
 * Thus, each salesperson passes in between 0 and 5 sales slips per day.
 * Assume that the information from all the slips for last month is available.
 *
 * Write a program that will read all this information for last month’s sales and
 * summarize the total sales by salesperson by product.
 * All totals should be stored in the two-dimensional array sales.
 * After processing all the information for last month, print the results in tabular
 * format with each column representing a particular salesperson and each row representing
 * a particular product. Cross total each row to get the total sales of each product for
 * last month;  cross  total  each  column  to  get  the  total sales  by  salesperson
 * for  last  month.  Your  tabular printout should include these cross totals to the
 * right of the totaled rows and to the bottom of the totaled columns.
 */
int main() {
    int tickets[20][3] = {
            // salesperson,product,dollarValue
            {1, 1, 291},
            {1, 2, 52},
            {1, 3, 280},
            {1, 4, 186},
            {1, 5, 374},
            {2, 1, 48},
            {2, 2, 210},
            {2, 3, 38},
            {2, 4, 141},
            {2, 5, 339},
            {3, 1, 427},
            {3, 2, 114},
            {3, 3, 229},
            {3, 4, 68},
            {3, 5, 116},
            {4, 1, 470},
            {4, 2, 740},
            {4, 3, 271},
            {4, 4, 318},
            {4, 5, 85}
    };

    int sales[6][5] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
    };

    // Import tickets
    for (int i = 0; i < 20; i++) {
        sales[tickets[i][1] - 1][tickets[i][0] - 1] = tickets[i][2];
    }

    // Sum rows
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            sales[5][i] += sales[j][i];
        }
    }

    // Sum columns
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            sales[i][4] += sales[i][j];
        }
    }

    // Complicated pretty-printing
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != 0) {
                if (i == 5) {
                    if (j != 4) {
                        printf(" ");
                    } else {
                        printf(" | ");
                    }
                } else {
                    if (j != 4) {
                        printf(", ");
                    } else {
                        printf(" | ");
                    }
                }
            }

            printf("%d", sales[i][j]);
        }
        printf("\n");

        if (i == 4) {
            printf("- - - - - - - - - - - -\n");
        }
    }

    return 0;
}