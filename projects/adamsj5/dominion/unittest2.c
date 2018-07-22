#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"

int main (int argc, char** argv) {
	struct gameState state;
    int check;

    //isGameOver function returns 1 if game is over and 0 is not over
    printf("Unit Test #2: Testing the isGameOver function\n");
    printf("----------------------------------------------\n");

    state.supplyCount[estate] = 8;
    state.supplyCount[duchy] = 8;
    state.supplyCount[province] = 8;

    //set number of Treasure cards
    state.supplyCount[copper] = 40;
    state.supplyCount[silver] = 40;
    state.supplyCount[gold] = 30;

    //Fill all supply piles with 8 cards
    for (int i = curse; i <= treasure_map; i++){
        state.supplyCount[i] = 8;
    }

    //Test 1: 3 supply piles(other than province) are empty with two of the cards being the first in the list and the last in the list
    state.supplyCount[curse] = 0;
    state.supplyCount[treasure_map] = 0;
    state.supplyCount[copper] = 0;

    check = isGameOver(&state);

    //refill piles
    state.supplyCount[curse] = 8;
    state.supplyCount[treasure_map] = 8;
    state.supplyCount[copper] = 8;

    if (check){
        printf("Test 1: PASSED-- Game ended correctly\n");
    }
    else{
        printf("Test 1: FAILED-- Game should have ended but did not\n");
    }

    //Test 2: 3 supply piles from 3 different types of cards(other than province) are empty 
    state.supplyCount[adventurer] = 0;
    state.supplyCount[estate] = 0;
    state.supplyCount[copper] = 0;

    check = isGameOver(&state);

    //refill supply piles
    state.supplyCount[adventurer] = 8;
    state.supplyCount[estate] = 8;
    state.supplyCount[copper] = 8;

    if (check){
        printf("Test 2: PASSED-- Game ended correctly\n");
    }
    else{
        printf("Test 2: FAILED-- Game should have ended but did not\n");
    }

    //Test 3: Province pile is empty
    state.supplyCount[province] = 0;


    check = isGameOver(&state);

    //refill supply piles
    state.supplyCount[province] = 8;

    if (check){
        printf("Test 3: PASSED-- Game ended correctly\n");
    }
    else{
        printf("Test 3: FAILED-- Game should have ended but did not\n");
    }

    //Test 4: 1 kingdom card and 1 victory card(other than province) pile is empty
    state.supplyCount[adventurer] = 0;
    state.supplyCount[estate] = 0;

    check = isGameOver(&state);

    //refill supply piles
    state.supplyCount[adventurer] = 8;
    state.supplyCount[estate] = 8;

    if (!check){
        printf("Test 4: PASSED-- Game continued correctly\n");
    }
    else{
        printf("Test 4: FAILED-- Game ended when it should have continued\n");
    }
    //Test 5: No piles are empty
    if (!check){
        printf("Test 5: PASSED-- Game continued correctly\n\n");
    }
    else{
        printf("Test 5: FAILED-- Game ended when it should have continued\n\n");
    }
    return 0;

}