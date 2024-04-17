#include <stdio.h>
#include <stdlib.h>
#include "../include/headerA3.h"

//This function takes a LL as its only parameter, counts, and returns the total number of cars (i.e., nodes) in the given L
int countCars (a3Car * headLL){
    int count = 0;
    struct car *current = headLL;

    while (current != NULL){
        count++;
        current = current->nextCar;
    }
    return count;
}
