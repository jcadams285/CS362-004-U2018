#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"

int main (int argc, char** argv) {
    struct gameState state, stateOrg;
    int numPlayers = 2;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
    int randomSeed = 5;
    int choice1 = 0;
    int choice2 = 0; 
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;

    //Start up game with two players
    initializeGame(numPlayers, k, randomSeed, &state);
    int player = whoseTurn(&state);
    //Copy state and store in stateOrg to check after test
    stateOrg = state;
    

    //Three areas to test: handcount, deckcount, playedcardcount
    printf("\nCard Test #4: Testing the Council Room card\n");
    printf("----------------------------------------------\n");

    cardEffect(council_room, choice1, choice2, choice3, &state, handPos, &bonus);
    //Test 1- handcount should have added 1 cards from deck - 1 card that they discard
    if (state.handCount[player] == (stateOrg.handCount[player] + 4 - 1)){
        printf("Test 1: PASSED-- Correct number of cards were added to handcount\n");
    }
    else{
        printf("Test 1: FAILED-- Incorrect number of cards were added to handcount\n");
    }

    //Test 2- deckcount should have 1 less card
    if (state.deckCount[player] == (stateOrg.deckCount[player] - 4)){
        printf("Test 2: PASSED-- Correct number of cards were taken from deck\n");
    }
    else{
        printf("Test 2: FAILED-- Incorrect number of cards were taken from deck\n");
    }

    //Test 3- playedcardcount should have 1 more card
    if (state.playedCardCount == (stateOrg.playedCardCount + 1)){
        printf("Test 3: PASSED-- Correct number of cards were added to discardCount\n");
    }
    else{
        printf("Test 3: FAILED-- Incorrect number of cards were added to discardCount\n");
    }

    //Test 4- buys should have added 1 to the value
    if (state.numBuys == (stateOrg.numBuys + 1)){
        printf("Test 4: PASSED-- Correct number of buy points were added\n");
    }
    else{
        printf("Test 4: FAILED-- Incorrect number of buy points were added\n");
    }

     //Test 5- other players should have one card added to their hand
    if (state.handCount[player + 1] == (stateOrg.handCount[player + 1] + 1)){
        printf("Test 5: PASSED-- next player recieved extra card\n\n");
    }
    else{
        printf("Test 5: FAILED-- next player did not recieve extra card\n\n");
    }

    return 0;
}
