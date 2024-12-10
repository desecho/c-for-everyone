/*
    Calculate the average weight of the northern elephant seal (Mirounga angustirostris).

    The file elephant_seal_data has to exist and it has to have 1000 weights.
*/
#include <stdio.h>

#define LENGTH 1000 // Number of weights to read
#define FILENAME "elephant_seal_data"

// Function to read weights from a file and store them in an array
void read_weights(FILE *file, int weights[]) {
    int count = 0;

    // Read weights from the file and store them in the array
    while (fscanf(file, "%d", &weights[count]) != EOF) {
        count++;
        if (count == LENGTH) {
            break;
        }
    }
}

double get_average(int weights[]) {
    int i;
    double sum = 0; // This has to be double due to the fact that the result of the calculation should be double
    // Calculate sum
    for (i = 0; i < LENGTH; i++) {
        sum += weights[i];
    }

    return sum / LENGTH;
}

int main() {
    int weights[LENGTH];
    double result;

    // Open file
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    read_weights(file, weights);

    // Close file
    fclose(file);

    result = get_average(weights);

    printf("Average weight: %f\n", result);

    return 0;
}
