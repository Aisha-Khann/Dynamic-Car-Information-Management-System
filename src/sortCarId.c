#include <stdio.h>
#include <stdlib.h>
#include "../include/headerA3.h"

//This function takes a LL and sorts it based on carId
void sortCarId(struct car **headLL) {
    // Check if the list is empty or has only one node
    if (*headLL == NULL || (*headLL)->nextCar == NULL) {
        return;
    }

    struct car *sorted = NULL;  // Initialize sorted list
    struct car *current = *headLL;


    while (current != NULL) {
        struct car *next = current->nextCar;
        // Insert current car into sorted list
        if (sorted == NULL || current->carId < sorted->carId) {
            current->nextCar = sorted;
            sorted = current;
        } else {
            struct car *temp = sorted;
            while (temp->nextCar != NULL && temp->nextCar->carId < current->carId) {
                temp = temp->nextCar;
            }
            current->nextCar = temp->nextCar;
            temp->nextCar = current;
        }
        current = next;
    }
    *headLL = sorted;  // Update head pointer to point to sorted list
}
