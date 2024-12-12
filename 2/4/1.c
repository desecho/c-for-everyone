/*
    Calculate the average and max values of integers in a provided file.

    The input file has to consist of integers separated by whitespace where the first integer
    is the number of integers after it.
    Example: 4  9  11  12  15

    Usage: <program> <input-filename>

    Author: Anton Samarchyan.
*/

#include <stdio.h>

#define OUTPUT_FILENAME "answer-hw3"
#define OUTPUT_MAX_CHARS 100

// Read integers from the file and store them in the array
void read_data(FILE *file, int data[]) {
    int i = 0;

    while (fscanf(file, "%d", &data[i]) != EOF) {
        i++;
    }
}

// Get average of an array of integers
double get_average(int data[], int size) {
    int i;
    double sum = 0; // This has to be double due to the fact that the result of the calculation should be double

    // Calculate sum
    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    return sum / size;
}

// Get maximum value from an array of integers
int get_max(int data[], int size) {
    int i;
    int max = data[0]; // Set a temporary max value to the first element of the array.

    // Get max value
    for (i = 0; i < size; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }

    return max;
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    int size; // Number of integers in a file
    double average;
    int max;
    char output[OUTPUT_MAX_CHARS];

    // Check that all required arguments are provided
    if (argc != 2) {
        printf("Usage: <program> <input-filename>\n");
        return 1;
    }

    // Open input file for reading
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Open output file for writing
    output_file = fopen(OUTPUT_FILENAME, "w");

    // Get number of integers
    fscanf(input_file, "%d", &size);

    int data[size];
    read_data(input_file, data);

    // Close input file
    fclose(input_file);

    average = get_average(data, size);
    max = get_max(data, size);

    // Create output
    sprintf(output, "Average: %lf\nMax: %d\n", average, max);

    // Print output
    printf("%s", output);

    // Write output into a file
    fputs(output, output_file);

    // Close output file
    fclose(output_file);

    return 0;
}
