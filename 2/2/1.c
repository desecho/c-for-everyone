/*
    Calendar calculator.

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

typedef enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{month m; int d;} date;

// date nextday(date d) {

// }


void printdate(date d) {
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
    default:
        printf("Error: Incorrect month %d", d.m);
        break;
    }

    printf(" %d\n", d.d);
}

int main() {

    date date1 = {jan, 1};
    printdate(date1);
    return 0;
}
