#include <stdio.h>
#include "../include/headerA3.h"

//addNewCar prompts the user to enter car data from
// standard input and add their information to the end of the linked list passed as a parameter to
// this function. The user enters the model, type of the car, its price and year of manufacture
void addNewCar (struct car ** headLL){

    //prompt user to enter the car data
    char model[MAX_LENGTH];
    char type[MAX_LENGTH];
    int year;
    double price;

    printf("Enter the car model: ");
    scanf("%s", model);

    printf("Enter the car type: ");
    scanf("%s", type);

    printf("Enter its year of manufacture: ");
    scanf("%d", &year);

    printf("Enter its price: CDN $ ");
    scanf("%lf", &price);

    //calculate carID
    int sum = 0;
    for (int i = 0; i < strlen(model); i++) {
        sum += model[i];    //sum of ascii values of characters in car model
    }

    int carId;
    int carIdExists;    //indicate whether carID already exists
    do {
        carIdExists = 0;    //reset to 0 for each iteration
        carId = sum + strlen(type); //calculate car id by adding to the length of type
        a3Car *current = *headLL;
        while (current != NULL){
            if (current->carId == carId){
                carIdExists = 1;    //set true
                break;
            }
            current = current->nextCar;
        }
        if (carIdExists){
            //if id already exists, generate a new carId
            int min = 1;
            int max = 999;
            carId += min + rand() % (max - min + 1);
        }
    } while (carIdExists);

    //print carID
    printf("Your computer-generated carId is %d\n\n", carId);


    //check if carID already exists in linked list
    a3Car *current = *headLL;
    while(current != NULL){
        if(current->carId == carId){
            int min = 1;
            int max = 999;
            carId += min + rand() % (max - min + 1);
            current = *headLL;  //restart loop
        } else {
            current = current ->nextCar;
        }
    }

    //allocate memory for new car node
    a3Car *newCar = (a3Car *)malloc(sizeof(a3Car));
    
    //assign data to the new car node
    strcpy(newCar->model, model);
    strcpy(newCar->type, type);
    newCar->year = year;
    newCar->price = price;
    newCar->carId = carId;
    newCar->nextCar = NULL;

    //add new car node to the end of the linked list
    if(*headLL == NULL){
        *headLL = newCar;   //if linked list is empty, new car becomes the head
    } else {
        current = *headLL;
        while(current->nextCar != NULL){
            current = current->nextCar;
        }
        current->nextCar = newCar;
    }

}