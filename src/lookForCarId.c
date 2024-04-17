#include <stdio.h>
#include <stdlib.h>
#include "../include/headerA3.h"

// lookForCarId takes 2 parameters (i.e., a linked list and a carId), it then searches the given LL for this carId. If
//found, its position in the given LL is returned, otherwise the function returns -1
int lookForCarId (struct car * headLL, int key){
    int position = 1;
    struct car *current = headLL;

    while (current != NULL){
        if (current->carId == key){
	    //does not print anything
            return position;
        }
        current = current->nextCar;
        position++;
    }
    return -1;  //when carId not found
}
