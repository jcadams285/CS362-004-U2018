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
    printf("\nCard Test #1: Testing the adventurer card\n");
    printf("----------------------------------------------\n");

    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);
    //First two tests only have copper in the deck as treasure cards
    //Test 1- handcount should have two added treasure cards and 1 less kingdom card
    if (state.handCount[player] == (stateOrg.handCount[player] + 2 - 1)){
        printf("Test 1: PASSED-- Correct number of cards were added to and played from handcount\n");
    }
    else{
        printf("Test 1: FAILED-- Incorrect number of cards were added to and played from handcount\n");
    }

    //Test 2- Original deckCount - current deckCount should equal discardCount - orginal discardCount + 2(treasure cards kept - 1 discard of adventure card)
    if (stateOrg.deckCount[player] - state.deckCount[player] == (state.discardCount[player] - stateOrg.discardCount[player] + 2)){
        printf("Test 2: PASSED-- Number of cards discarded equals the number of cards drawn - 2\n");
    }
    else{
        printf("Test 2: FAILED-- Number of cards discarded does not equal the number of cards drawn\n");
    }

    //Start up game with two players
    initializeGame(numPlayers, k, randomSeed, &state);

    //Copy state and store in stateOrg to check after test
    stateOrg = state;

    //add gold and kingdom cards to the deck 
    state.deckCount[player] = 10;
    for (int i = 0; i < 10; i++){
      if (i % 2 == 0){
        state.deck[player][i] = gold;
      }
      else{
        state.deck[player][i] = mine;
      }
    }

    //Copy state and store in stateOrg to check after test
    stateOrg = state;

    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

    //Test 3- handcount should have two added treasure cards and 1 less kingdom card
    if (state.handCount[player] == (stateOrg.handCount[player] + 2 - 1)){
        printf("Test 3: PASSED-- Correct number of cards were added to and played from handcount\n");
    }
    else{
        printf("Test 3: FAILED-- Incorrect number of cards were added to and played from handcount\n");
    }

    //Test 4- Original deckCount - current deckCount should equal discardCount - orginal discardCount + 2(treasure cards kept - 1 discard of adventure card)
    if (stateOrg.deckCount[player] - state.deckCount[player] == (state.discardCount[player] - stateOrg.discardCount[player] + 2)){
        printf("Test 4: PASSED-- Number of cards discarded equals the number of cards drawn - 2\n");
    }
    else{
        printf("Test 4: FAILED-- Number of cards discarded does not equal the number of cards drawn\n");
    }


        //Start up game with two players
    initializeGame(numPlayers, k, randomSeed, &state);

    //Copy state and store in stateOrg to check after test
    stateOrg = state;

    //add silver and kingdom cards to the deck 
    state.deckCount[player] = 10;
    for (int i = 0; i < 10; i++){
      if (i % 2 == 0){
        state.deck[player][i] = silver;
      }
      else{
        state.deck[player][i] = mine;
      }
    }

    //Copy state and store in stateOrg to check after test
    stateOrg = state;

    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

    //Test 3- handcount should have two added treasure cards and 1 less kingdom card
    if (state.handCount[player] == (stateOrg.handCount[player] + 2 - 1)){
        printf("Test 5: PASSED-- Correct number of cards were added to and played from handcount\n");
    }
    else{
        printf("Test 5: FAILED-- Incorrect number of cards were added to and played from handcount\n");
    }

    //Test 4- Original deckCount - current deckCount should equal discardCount - orginal discardCount + 2(treasure cards kept - 1 discard of adventure card)
    if (stateOrg.deckCount[player] - state.deckCount[player] == (state.discardCount[player] - stateOrg.discardCount[player] + 2)){
        printf("Test 6: PASSED-- Number of cards discarded equals the number of cards drawn - 2\n\n");
    }
    else{
        printf("Test 6: FAILED-- Number of cards discarded does not equal the number of cards drawn\n\n");
    }

    return 0;
}