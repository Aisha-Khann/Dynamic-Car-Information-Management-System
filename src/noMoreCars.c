#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/headerA3.h"

//This function first prompts the user to confirm with a y or n, and then removes all cars from the current LL. 
//Note that user must be repeatedly prompted to enter a valid value of ‘y’ or ‘n’. It then prints the message “All
//removed. Linked list is now empty”
void noMoreCars(a3Car **headLL) {
    char choice[10]; // Adjust the size according to your input needs

    do {
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        fgets(choice, sizeof(choice), stdin); // Read the input as a string first
        choice[strcspn(choice, "\n")] = 0; // Remove the newline character if present

        // Check if the input is valid
        if (strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0) {
            printf("Invalid input. Please enter y or n.\n");
        }
    } while (strcmp(choice, "y") != 0 && strcmp(choice, "n") != 0);

    if (strcmp(choice, "y") == 0) {
        // Free memory for each node in the linked list
        while (*headLL != NULL) {
            struct car *temp = *headLL;
            *headLL = (*headLL)->nextCar;
            free(temp);
        }
        printf("All removed. Linked list is empty.\n");
    }
}
