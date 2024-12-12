/*
    Date calculator.

    It can output the next day and it can print a date.

    Written by Anton Samarchyan.
*/

#include <stdio.h>

#define MONTHS_NUM 12
#define DATES_INPUT_NUM 5

typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;

typedef struct date{
    month m;
    int d;
} date;

// Get the next day
date nextday(date d) {
    int days_in_month[MONTHS_NUM] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date result;

    if (d.d == days_in_month[d.m]) { // Case where it's the last day of the month
        result.d = 1;
        result.m = (d.m + 1) % MONTHS_NUM;
    } else {
        result.d = d.d + 1;
        result.m = d.m;
    }

    return result;
}

// Print date
void printdate(date d) {
    char* months[MONTHS_NUM] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    printf("%s %d\n", months[d.m], d.d);
}

int main() {
    date dates[DATES_INPUT_NUM] = {{jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    int i;

    for (i = 0; i < DATES_INPUT_NUM; i++) {
        printdate(dates[i]);
        printdate(nextday(dates[i]));

        if (i < DATES_INPUT_NUM - 1) { // Do not to print the last blank line.
            printf("\n");
        }
    }

    return 0;
}
