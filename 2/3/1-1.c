/*
    Sort list of integers.

    It generates an array of 100 random integers. Then it converts it to a list. Then it sorts the list with bubble sort.
    It outputs the unsorted and sorted lists.

    Written by Anton Samarchyan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_INTEGERS 10
#define MAX_INTEGER 1000

typedef struct list{
    int data;
    struct list *next;
} list;

// Create a list from a value
list* create_list(int d) {
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// Add value to the front of a list
list* add_to_front(int d, list* l) {
    list* head = create_list(d);
    head -> next = l;
    return head;
}

// Print list in rows of 5 integers
void print_list(list *l) {
    int i = 1;
    while (l != NULL) {
        printf("%d ", l-> data);
        if (i % 5 == 0) {
            printf("\n");
        }
        l = l -> next;
        i++;
    }
}

// Convert an array to a list
list* array_to_list(int numbers[]) {
    // Create a list with the first element
    list* l = create_list(numbers[0]);
    int i;

    // Add all other elements to the front of the list
    for (i = 1; i < NUM_INTEGERS; i++) {
        l = add_to_front(numbers[i], l);
    }

    return l;
}

// Generate random numbers
void generate_random_numbers(int numbers[]) {
    int i;
    srand(time(NULL)); // Seed the random number generator

    // Generate random numbers
    for (i = 0; i < NUM_INTEGERS; i++) {
        numbers[i] = rand() % (MAX_INTEGER + 1);
    }
}

// Sort the list
void sort_list(list *l) {
    int a, b, i;

    // Repeat for all integers.
    for (i = 0; i < NUM_INTEGERS; i++) {
        list *head = l;

        while (l -> next != NULL) {
            a = l -> data; // First element value
            b = l -> next -> data; // Next element value
            if (a > b) { // Swap values if first element is bigger than the second element
                l -> data = b;
                l -> next -> data = a;
            }

            l = l -> next;
        }

        l = head;
    }
}

int main() {
    int numbers[NUM_INTEGERS];
    int i;

    generate_random_numbers(numbers);

    list* l = array_to_list(numbers);

    // Print unsorted list
    printf("Unsorted list:\n");
    print_list(l);
    printf("\n");

    sort_list(l);

    // Print sorted list
    printf("Sorted list:\n");
    print_list(l);

    return 0;
}
