#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/headerA3.h"


//using command line arguments
int main(int argc, char * argv[]){

    //menu prompt
    struct car *headLL = NULL; // Initialize the linked list to be empty
    char fileName[MAX_LENGTH];
    int optionSelected;

    while (1) {
        printf("Menu Options:\n");
        printf("1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");
        printf("\nChoose a menu option: ");

        scanf("%d", &optionSelected);
        // Clear input buffer
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

            switch (optionSelected){
                case 1:
                    //function 1- add new car
                    srand(time(NULL)); // random number generator
                    addNewCar(&headLL);    // Add a new car
                    break;
                case 2:
                    //function 2- loadCarData
                    loadCarData(&headLL, fileName);
                    break;
                case 3:
                    if (headLL == NULL) {
                        printf("No cars found.\n");
                        break;
                    }
                    //function 3- printAll
                    printAll(headLL);
                    break;
                case 4:
                    //function 4- print data of nth car
                    if (headLL == NULL) {
                        printf("No cars found.\n");
                        break;
                    }
		            int totalCars = countCars(headLL);
		            int position;
		            do {
    		            printf("Enter a position: ");
		                scanf("%d", &position);
		                if (position < 1 || position > totalCars){
		                printf("Invalid position. Please enter a position between 1 and %d.\n", totalCars);
		                }
		            } while (position < 1 || position > totalCars);
                    //function call
		            printOne(headLL, position);
		            break;
                case 5:
                    //function 5- look for car position by Id
                    if (headLL == NULL){
                        printf("No cars found.\n");
                        break;
                    }
                    int carId;
                    printf("Enter a car ID: ");
                    scanf("%d", &carId);
		            position = lookForCarId(headLL, carId);
                    if (position == -1){
                        printf("Car not found.\n");
                    } else {
	                printf("Position = %d\n", position);
		            }
                    break;
		        case 6:
                    if (headLL == NULL){
                        printf("No cars found.\n");
                        break;
                    }
                    char modelType[100];
                    printf("Enter the model and type (separated by a space): ");
                    fgets(modelType, sizeof(modelType), stdin);
                    
                    // Remove newline character if present
                    int len = strlen(modelType);
                    if (modelType[len - 1] == '\n') {
                        modelType[len - 1] = '\0'; // Replace newline character with null terminator
                    } 

                    // struct car *temp = headLL;

                    int carPosition = lookForCarModelType(headLL, modelType);
                    if (carPosition == -1) {
                        printf("Car not found.\n");
                    } else {
                        printf("Position = %d\n", carPosition);
                    }
                    
                    break;
		        case 7:
                    if (headLL == NULL) {
                        printf("No cars found.\n");
                        break;
                    }
                    //function 7- count number of cars
		            int printTotalCars = countCars(headLL);
                    printf("Total number of cars= %d\n", printTotalCars);
                    break;
                case 8:
                    if (headLL == NULL){
                        printf("No cars found.\n");
                        break;
                    }
                    sortCarId(&headLL); // Call the function to sort the linked list based on carId
                    printf("sorted.\n");
                    
                    break;
                case 9:
                    if (headLL == NULL) {
                        printf("No cars found.\n");
                        break;
                    }

                    //count cars in LL
                    int newTotalCars = countCars(headLL);

                    printf("Currently there are %d cars.\n", newTotalCars);
                    int whichOne;

                    do {
                        printf("Which car do you wish to remove – enter a value between 1 and %d: ", newTotalCars);
                        scanf("%d", &whichOne);
                        if (whichOne < 1 || whichOne > newTotalCars) {
                        printf("Invalid input. Please enter a value between 1 and %d.\n", newTotalCars);
                        } else {
                            //call the function
                            oneLessCar(&headLL, whichOne);
                        }
                    } while (whichOne < 1 || whichOne > newTotalCars);
                    
                    break;
                case 10:
                    if (headLL == NULL) {
                        printf("No cars found.\n");
                        break;
                    }

                    noMoreCars(&headLL);
                    break;
                case 11:     
                    printf("Exiting.\n");
                    return 0;
                default:
                    printf("Invalid choice. Please enter a valid option (1-11).\n");
            }
    }
    return 0;
}
