#include <stdio.h>

void calcAndCountSalaries(const double gross[], int grossc, int counter[]);

/*
 * (15 points) Use a one-dimensional array to solve the following problem.
 * A company pays its salespeople on a commission basis.
 * The salespeople receive $200 per week plus 9% of their gross sales for that week.
 * For example, a salesperson who grosses $3,000 in sales in a week receives
 * $200 plus 9% of $3,000, or a total of $470.
 *
 * Write a C program (using an array of counters) that determines how  many  of  the
 * salespeople  earned  salaries  in  each  of  the  following  ranges
 * (assume that each salesperson’s salary is truncated to an integer amount):
 *      a) $200–299
 *      b) $300–399
 *      c) $400–499
 *      d) $500–599
 *      e) $600–699
 *      f) $700–799
 *      g) $800–899
 *      h) $900–999
 *      i) $1000 and over
 */
int main() {
    double salesGross[20] = {
            6912.08, 6486.24, 231.58, 1475.14, 4062.05,
            9826.46, 6829.05, 9119.83, 8656.83, 956.46,
            801.26, 9415.97, 6849.04, 7709.89, 9488.75,
            9601.22, 8496.19, 1620.50, 402.54, 7916.11
    };

    int salesCounter[9] = {0,0,0,0,0,0,0,0,0};

    calcAndCountSalaries(salesGross, 20, salesCounter);

    for (int i = 0; i < 9; i++) {
        switch (i) {
            case 0:
                printf("$200-299: %d\n", salesCounter[i]);
                break;
            case 1:
                printf("$300-399: %d\n", salesCounter[i]);
                break;
            case 2:
                printf("$400-499: %d\n", salesCounter[i]);
                break;
            case 3:
                printf("$500-599: %d\n", salesCounter[i]);
                break;
            case 4:
                printf("$600-699: %d\n", salesCounter[i]);
                break;
            case 5:
                printf("$700-799: %d\n", salesCounter[i]);
                break;
            case 6:
                printf("$800-899: %d\n", salesCounter[i]);
                break;
            case 7:
                printf("$900-999: %d\n", salesCounter[i]);
                break;
            case 8:
                printf("$1000+: %d\n", salesCounter[i]);
                break;
        }
    }

    return 0;
}

void calcAndCountSalaries(const double gross[], int grossc, int counter[]) {
    for (int i = 0; i < grossc; i++) {
        int adjustedSalary = (int) (gross[i] * 0.09 + 200);

        if (adjustedSalary >= 200 && adjustedSalary < 300) {
            counter[0]++;
        } else if (adjustedSalary < 400) {
            counter[1]++;
        } else if (adjustedSalary < 500) {
            counter[2]++;
        } else if (adjustedSalary < 600) {
            counter[3]++;
        } else if (adjustedSalary < 700) {
            counter[4]++;
        } else if (adjustedSalary < 800) {
            counter[5]++;
        } else if (adjustedSalary < 900) {
            counter[6]++;
        } else if (adjustedSalary < 1000) {
            counter[7]++;
        } else {
            counter[8]++;
        }
    }
}