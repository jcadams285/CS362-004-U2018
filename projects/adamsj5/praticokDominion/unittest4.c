#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"

int main (int argc, char** argv) {
    //Array that holds the cost of each card
    int price[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
    
    //getCost function returns cost of card or -1 if cost not found
    printf("Unit Test #4: Testing the getCost function\n");
    printf("----------------------------------------------\n");

    //Tests 1-27: Check each card to make sure correct cost is returned
    for (int i = 0; i < 27; i++){
        if (price[i] == getCost(i)){
            printf("Test %d: PASSED-- correct cost returned\n", i+1);
        }
        else{
            printf("Test %d: FAILED-- Incorrect cost returned\n", i+1);
        }
    }

    //Check if card number is invalid
    int j = 50;
    if (getCost(j) == -1){
            printf("Test 28: PASSED-- Invalid card found\n\n");
        }
        else{
            printf("Test 28: FAILED-- Invalid card not found\n\n");
        }

	return 0;
}
