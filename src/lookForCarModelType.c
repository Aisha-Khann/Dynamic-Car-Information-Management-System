#include <stdio.h>
#include <stdlib.h>
#include "../include/headerA3.h"

// the function takes 2 parameters (i.e., a linked list and a single string that stores the car model and
// type), it then searches the given LL for this car model and type. If found, its position in the given
// LL is returned, otherwise the function returns -1
int lookForCarModelType(struct car *headLL, char key[100]) {
    int position = 1;
    struct car *current = headLL;

    while (current != NULL) {
        // Compare model and type with key
        //do not print anything
        //strstr addresses the first string and the second string separately
        //first we check if the first word matches the model, and then if the second one matches the type
        if (strstr(key, current->model) != NULL && strstr(key, current->type) != NULL) {
            return position;
        }
        current = current->nextCar;
        position++;
    }
    // If no match found
    return -1;
}
