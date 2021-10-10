#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double calculateCharges(double hours);

/*
 * (15 points) A car rental service charges a minimum fee of $25.00 to rent a car for 8 hours,
 * and charges an additional $5 per hour after 8 hours.
 * The maximum charge per day is $50 exclusive of service tax.
 * The company charges an additional $0.50 per hour as service tax.
 * Assume that no car is rented for more than 72 hours at a time.
 * If a car is rented for more than 24 hours, then rental is calculated on a daily basis.
 *
 * Write a program that calculates and prints the rental charges for
 * each of three customers who rented cars from this agency yesterday.
 * You should enter the hours for which the car has been rented for each customer.
 * Your program should print the results in a neat tabular format and should calculate
 * and print the total of yesterday’s receipts.
 * The program should use the function calculateCharges to determine the charges for each customer.
 * Your outputs should appear in the following format:
 *      Car     Hours    Charge
 *      1       12       56.00
 *      2       34       117.00
 *      3       48       124.00
 *      TOTAL   94       297.00
 */
int main() {
    char buffer[5];
    size_t successfulNums = 0;
    long current;
    int hours[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double charges[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (1) {
        printf("Insert hours for Car #%lu (q to quit) > ", successfulNums + 1);
        fgets(buffer, 5, stdin);

        if (strcmp(buffer, "q\n") == 0) {
            break;
        }

        current = strtol(buffer, NULL, 10);

        if (current <= 0) {
            printf("Invalid format / too small!\n");
            continue;
        }

        hours[successfulNums] = (int) current;

        successfulNums++;
    }

    for (int i = 0; i < successfulNums; i++) {
        charges[i] = calculateCharges(hours[i]);
    }

    printf("Car      Hours     Charge\n");
    for (int i = 0; i < successfulNums; i++) {
        printf("%d        %d        %.2f\n", i + 1, hours[i], charges[i]);
    }

    int totalHours = 0;
    for (int i = 0; i < successfulNums; i++) {
        totalHours += hours[i];
    }

    double totalCharge = 0;
    for (int i = 0; i < successfulNums; i++) {
        totalCharge += charges[i];
    }

    printf("TOTAL    %d        %.2f\n", totalHours, totalCharge);

    return 0;
}

double calculateCharges(double hours) {
    double total = hours * .5;
    while (hours >= 24) {
        total += 50;
        hours -= 24;
    }

    if (hours <= 0) {
        return total;
    }

    total += 25;
    hours -= 8;

    int hourAcc = 0;
    while (hours > 0 && hourAcc < 25) {
        hourAcc += 5;
        hours -= 1;
    }

    total += hourAcc;
    return total;
}