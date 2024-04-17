#include <stdio.h>
#include "../include/headerA3.h"

//This function loads car data from a given text file and adds them to the current linked list.
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){
    fileName = "src/inputFile.txt";
    FILE *file = fopen(fileName, "r");
    if (file == NULL){
        printf("Error opening the file.\n");
        return;
    }

    char line[100]; //assuming max length of line is 100
    while (fgets(line, sizeof(line), file)){
        struct car newCar;
        //read data from text file until comma is encountered
        sscanf(line, "%d,%[^,],%[^,],%d,%lf", &newCar.carId, newCar.model, newCar.type, &newCar.year, &newCar.price);
        newCar.carId = -1; // Placeholder value for carId from file

        //check if id is unique
        a3Car *current = *headLL;
        int unique = 1;
        int sum = 0;
        for (int i = 0; i < strlen(newCar.model); i++){
            sum += newCar.model[i]; //sum of ascii values
        }
        int carId = sum +strlen(newCar.type);   //same approach as first function

        do {
            unique = 1; //reset for each iteration
            current = *headLL;
            while (current != NULL){
                if (current->carId == carId){
                    unique = 0; //when id already exists
                    break;
                }
                current = current->nextCar;
            }
            if (!unique){
                int min = 1;
                int max = 999;
                carId += min + rand() % (max - min + 1);
            }
        } while (!unique);
        
        newCar.carId = carId; // Assign the calculated unique carId

        // Add new car to the linked list
        //allocate memory
        a3Car *newNode = (a3Car *)malloc(sizeof(a3Car));

        //assign data to the new car node

        *newNode = newCar;
        newNode->nextCar = NULL;

        if (*headLL == NULL) {
            *headLL = newNode;
        } else {
            current = *headLL;
            while (current->nextCar != NULL) {
                current = current->nextCar;
            }
            current->nextCar = newNode;
        }

    }
    
    fclose(file);
}