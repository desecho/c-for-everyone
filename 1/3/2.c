/*
    Print a table of values for sine and cosine between (0, 1)
*/

#include<stdio.h>
#include<math.h>

int main(void) {
    double interval;
    int i;

    // Print header
    printf("Value\t\tSine\t\tCosine\n");
    printf("----------------------------------------\n");

    // Print sine/cosine table
    for(i = 0; i < 11; i++) {
        interval = i/10.0;
        printf("%lf\t%lf\t%lf\n", interval, sin(interval), cos(interval));
    }

    return 0;
}
