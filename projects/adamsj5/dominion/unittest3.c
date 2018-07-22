#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"

int main (int argc, char** argv) {
    struct gameState state;
    int numPlayers = 4;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
    int randomSeed = 5;

    initializeGame(numPlayers, k, randomSeed, &state);

    //isGameOver function returns 1 if game is over and 0 is not over
    printf("Unit Test #3: Testing the endTurn function\n");
    printf("----------------------------------------------\n");

    //Test 1- Player 1 ends turn

    endTurn(&state);

    if (state.whoseTurn == 1){
        printf("Test 1: PASSED-- Game ended turn correctly\n");
    }
    else{
        printf("Test 1: FAILED-- Game did not end turn correctly\n");
    }

    //Test 2- Player 2 ends turn

    endTurn(&state);

    if (state.whoseTurn == 2){
        printf("Test 2: PASSED-- Game ended turn correctly\n");
    }
    else{
        printf("Test 2: FAILED-- Game did not end turn correctly\n");
    }

    //Test 3- Player 3 ends turn

    endTurn(&state);

    if (state.whoseTurn == 3){
        printf("Test 3: PASSED-- Game ended turn correctly\n");
    }
    else{
        printf("Test 3: FAILED-- Game did not end turn correctly\n");
    }

    //Test 4- Player 4 ends turn

    endTurn(&state);

    if (state.whoseTurn == 0){
        printf("Test 4: PASSED-- Game ended turn correctly\n\n");
    }
    else{
        printf("Test 4: FAILED-- Game did not end turn correctly\n\n");
    }

    return 0;
}
