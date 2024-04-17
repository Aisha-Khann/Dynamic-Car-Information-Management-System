#include <stdio.h>
#include "../include/headerA3.h"

//This function takes a position number (i.e., an int) as its input parameter and prints 
//the data of the car at that position in the current LL
void printOne (struct car * headLL, int whichOne){

    int count = 0;
    struct car *current = headLL;
    while (current != NULL){
        count++;
        if(count == whichOne){
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
            return;
        }
        current = current-> nextCar;
    }
}
