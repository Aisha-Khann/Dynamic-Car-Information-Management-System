#include <stdio.h>
#include <stdlib.h>
#include "../include/headerA3.h"

//This function takes 2 parameters, a linked list and an int value to indicate the node number to remove. 
//It then removes that node (and the car information stored in it) from the LL
void oneLessCar(struct car **headLL, int whichOne) {
    if (*headLL == NULL) {
        // Empty linked list
        return;
    }

    // Special case: the node to be removed is actually the first node in the LL
    if (whichOne == 1) {
        struct car *temp = *headLL;
        *headLL = (*headLL)->nextCar;
        free(temp);
        return;
    }

    // Traverse the linked list to find the node to be removed
    struct car *prev = NULL;
    struct car *current = *headLL;
    int count = 1;
    while (current != NULL && count < whichOne) {
        prev = current;
        current = current->nextCar;
        count++;
        free(prev);
    }

    
    if (prev == NULL){
        // Remove the head node
        *headLL = current->nextCar;
    } else {
        prev->nextCar = current->nextCar;
    }
    free(current);
}
