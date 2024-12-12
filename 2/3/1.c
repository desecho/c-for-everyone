/*
    Print elements info.

    It outputs a table of elements info.

    Written by Anton Samarchyan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 10
#define MAX_NAME_CHARS 10
#define MAX_SYMBOL_CHARS 3

typedef struct element {
    char name[MAX_NAME_CHARS];
    char symbol[MAX_SYMBOL_CHARS];
    double weight;
} element;

typedef struct list{
    element data;
    struct list *next;
} list;

list* create_list(element d) {
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(element d, list* l) {
    list* head = create_list(d);
    head -> next = l;
    return head;
}

void print_list(list *l) {
    printf("\n");
    // Print header
    printf("%-10s %-10s %-10s\n", "Name", "Symbol", "Weight");
    printf("----------------------------\n");
    // Print data
    while (l != NULL) {
        printf("%-10s %-10s %-10.3f\n", l-> data.name, l -> data.symbol, l -> data.weight);
        l = l -> next;
    }
}

element input_element(int n) {
    char name[MAX_NAME_CHARS];
    char symbol[MAX_SYMBOL_CHARS];
    double weight;
    element el;

    // Prompts for input
    printf("Enter name of element #%d: ", n);
    scanf("%s", name);
    printf("Enter symbol of element #%d: ", n);
    scanf("%s", symbol);
    printf("Enter weight of element #%d: ", n);
    scanf("%lf", &weight);
    printf("\n");

    strcpy(el.name, name);
    strcpy(el.symbol, symbol);
    el.weight = weight;

    return el;
}

list* elements_to_list(element elements[]) {
    list* l = create_list(elements[0]);
    int i;

    for (i = 1; i < NUM_ELEMENTS; i++) {
        l = add_to_front(elements[i], l);
    }

    return l;
}

int main() {
    element elements[NUM_ELEMENTS];
    int i;

    for (i = 1; i <= NUM_ELEMENTS; i++) {
        elements[i-1] = input_element(i);
    }

    list* l = elements_to_list(elements);
    print_list(l);
    return 0;
}
