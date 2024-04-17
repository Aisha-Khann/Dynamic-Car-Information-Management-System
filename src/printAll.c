#include <stdio.h>
#include "../include/headerA3.h"

// This function prints the data of all cars currently in the LL
void printAll (struct car * headLL) {

    int count = 0;
    struct car *current = headLL;

    while (current != NULL) {
        count++;
        printf("Car # %d:\n", count);
        printf("Car id: %d\n", current->carId);
        printf("Model: %s\n", current->model);
        printf("Type: %s\n", current->type);
        printf("Price: CDN $");
        //print the price by converting to an integer and printing that first
        int price = (int)current->price / 1000;
        //print whats left after the comma
        int priceRemainder = (int)(current->price) % 1000;
        printf("%d,", price);
        //print the fraction part using 2 leading zeros
        printf("%02d%.2lf\n", priceRemainder, current->price - (price * 1000 + priceRemainder));
        printf("Year of Manufacture: %d\n", current->year);
        printf("\n");
        current = current->nextCar;
    }
    printf("Currently, there are %d cars\n", count);
}