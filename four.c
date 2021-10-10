#include <stdio.h>

void monthSwitch(int choice);
void monthArray(int choice);

/*
 * (10 points) Write a C program that accepts a month in digit from the user. Display the month in words.
 * If number is not between 1 and 12 display message “Invalid Month”.
 * (Use‘switch’).
 */
int main() {
    // Inefficient switch method
    monthSwitch(1);
    // Much cleaner and faster array method
    monthArray(1);

    printf("\nMy birthday is in: ");
    monthArray(8);
    return 0;
}

void monthSwitch(int choice) {
    switch (choice) {
        case 1:
            printf("January!\n");
            break;
        case 2:
            printf("February!\n");
            break;
        case 3:
            printf("March!\n");
            break;
        case 4:
            printf("April!\n");
            break;
        case 5:
            printf("May!\n");
            break;
        case 6:
            printf("June!\n");
            break;
        case 7:
            printf("July!\n");
            break;
        case 8:
            printf("August!\n");
            break;
        case 9:
            printf("September!\n");
            break;
        case 10:
            printf("October!\n");
            break;
        case 11:
            printf("November!\n");
            break;
        case 12:
            printf("December!\n");
            break;
        default:
            printf("Invalid month!\n");
    }
}

void monthArray(int choice) {
    char* months[] = {
            "January!",
            "February!",
            "March!",
            "April!",
            "May!",
            "June!",
            "July!",
            "August!",
            "September!",
            "October!",
            "November!",
            "December!"
    };
    printf("%s", months[choice - 1]);
}