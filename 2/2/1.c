/*
    Date calculator.

    It can output the next day and it can print a date.
*/

#include <stdio.h>

#define DAYS_IN_JAN 31
#define DAYS_IN_FEB 28
#define DAYS_IN_MAR 31
#define DAYS_IN_APR 30
#define DAYS_IN_MAY 31
#define DAYS_IN_JUN 30
#define DAYS_IN_JUL 31
#define DAYS_IN_AUG 31
#define DAYS_IN_SEP 30
#define DAYS_IN_OCT 31
#define DAYS_IN_NOV 30
#define DAYS_IN_DEC 31

#define MONTHS_NUM 12

#define DATES_INPUT_NUM 5

typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{month m; int d;} date;

// Get the next day
date nextday(date d) {
    int days_in_month;
    date result;

    // Get days in month value for each month
    switch (d.m) {
        case jan:
            days_in_month = DAYS_IN_JAN;
            break;
        case feb:
            days_in_month = DAYS_IN_FEB;
            break;
        case mar:
            days_in_month = DAYS_IN_MAR;
            break;
        case apr:
            days_in_month = DAYS_IN_APR;
            break;
        case may:
            days_in_month = DAYS_IN_MAY;
            break;
        case jun:
            days_in_month = DAYS_IN_JUN;
            break;
        case jul:
            days_in_month = DAYS_IN_JUL;
            break;
        case aug:
            days_in_month = DAYS_IN_AUG;
            break;
        case sep:
            days_in_month = DAYS_IN_SEP;
            break;
        case oct:
            days_in_month = DAYS_IN_OCT;
            break;
        case nov:
            days_in_month = DAYS_IN_NOV;
            break;
        case dec:
            days_in_month = DAYS_IN_DEC;
            break;
        default: // Should not normally occur
            printf("Error: Incorrect month %d\n", d.m);
            return result;
    }

    // Calculate the next day
    if (d.d == days_in_month) {
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
    // Print month
    switch (d.m) {
        case jan:
            printf("January");
            break;
        case feb:
            printf("February");
            break;
        case mar:
            printf("March");
            break;
        case apr:
            printf("April");
            break;
        case may:
            printf("May");
            break;
        case jun:
            printf("June");
            break;
        case jul:
            printf("July");
            break;
        case aug:
            printf("August");
            break;
        case sep:
            printf("September");
            break;
        case oct:
            printf("October");
            break;
        case nov:
            printf("November");
            break;
        case dec:
            printf("December");
            break;
        default: // Should not normally occur
            printf("Error: Incorrect month %d", d.m);
            break;
    }
    // Print day
    printf(" %d\n", d.d);
}

int main() {
    date dates[DATES_INPUT_NUM] = {{jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    int i;

    for (i = 0; i < DATES_INPUT_NUM; i++) {
        printdate(dates[i]);
        printdate(nextday(dates[i]));

        if (i < DATES_INPUT_NUM - 1) { // Make sure not to print the last blank line.
            printf("\n");
        }
    }

    return 0;
}
