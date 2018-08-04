#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int NUMTESTS = 1000000;

//Returns a randon int within the range given
int randomRange(int min, int max){
    int number = rand();
    number = (number % (max + 1 - min) + min);
    return number;
}

//Sets up game state with random number of players with random cards and action points
void randomGameState(struct gameState *state, int numPlayers){
    state->playedCardCount = 0;
    //Num players must be between 2-4
    state->numPlayers = numPlayers;
    for (int i = 0; i < numPlayers; i++){
        state->discardCount[i] = 0;
    }
    state->whoseTurn = randomRange(0, (numPlayers - 1));
    //You start with 1 action point and typically wouldn't have more than 3 at a time
    state->numActions = randomRange(1, 3);
    //Set each hand up with cards
    for (int i = 0; i < numPlayers; i++){
        int max_hand = state->handCount[i];
        for(int j = 0; j < max_hand; j++){
            state->hand[i][j] = randomRange(curse, treasure_map);
        }
    }
    //Set each deck up with cards
    //Deck usually is never lower than 5
    for (int i = 0; i < numPlayers; i++){
        int max_deck = state->deckCount[i];
        for(int j = 0; j < max_deck; j++){
            if(j == 0 || j == (max_deck-1)){
                state->deck[i][j] = randomRange(silver, gold);
            }
            else{
                state->deck[i][j] = randomRange(curse, treasure_map);
            }
            
        }
    }
}

int main (int argc, char** argv) {
    srand(time(NULL));

    struct gameState state, stateOrg;
    int check = 1;

     printf("\nRandom Card Test: Testing the adventurer card\n");
     printf("--------------------------------------------------\n");

    

    for(int i = 0; i < NUMTESTS; i++){
        //Random number of players
        int numPlayers = randomRange(2, 4);
        int randomSeed = randomRange(1, 1000);
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        //Variables that are not used in adventurer card set to 0
        int choice1 = 0;
        int choice2 = 0; 
        int choice3 = 0;
        int handPos = 0;
        int bonus = 0;

        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

        //First two tests only have copper in the deck as treasure cards
        //Test 1- handcount should have two added treasure cards and 1 less kingdom card
        if (state.handCount[player] != (stateOrg.handCount[player] + 2 - 1)){
            printf("Test 1: FAILED-- Incorrect number of cards found in handCount\n");
            check = 0;
            break;
        }
    }
    if(check){
        printf("Test 1: PASSED-- Correct number of handCount found in each of the tests\n");
    }

    check = 1;
    for(int i = 0; i < NUMTESTS; i++){
        //Random number of players
        int numPlayers = randomRange(2, 4);
        int randomSeed = randomRange(1, 10);
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        //Variables that are not used in adventurer card set to 0
        int choice1 = 0;
        int choice2 = 0; 
        int choice3 = 0;
        int handPos = 0;
        int bonus = 0;

        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);
        //Three areas to test: handcount, deckcount, playedcardcount

        //Check to make sure 2 treasure cards were added to the hand
        int treasureBefore = 0;
        int treasureAfter = 0;
        for(int k = 0; k < stateOrg.handCount[player]; k++){
            if(state.hand[player][k] == gold || state.hand[player][k] == silver || state.hand[player][k] == copper){
                treasureBefore++;
            }
        }
        for(int k = 0; k < state.handCount[player]; k++){
            if(state.hand[player][k] == gold || state.hand[player][k] == silver || state.hand[player][k] == copper){
                treasureAfter++;
            }
        }

        if(treasureAfter - 2 != treasureBefore){
            printf("Test 2: FAILED-- Incorrect number of treasure cards added to hand\n");
            check = 0;
        }
    }
    if(check){
        printf("Test 2: PASSED-- Correct number of treasure cards added to hand\n");
    }

    check = 1;
    for(int i = 0; i < NUMTESTS; i++){
        //Random number of players
        int numPlayers = randomRange(2, 4);
        int randomSeed = randomRange(1, 10);
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        //Variables that are not used in adventurer card set to 0
        int choice1 = 0;
        int choice2 = 0; 
        int choice3 = 0;
        int handPos = 0;
        int bonus = 0;


        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);
        //Three areas to test: handcount, deckcount, playedcardcount

        //Check to make sure 2 treasure cards were added to the hand
        int treasureBefore = 0;
        int treasureAfter = 0;
        for(int k = 0; k < stateOrg.discardCount[player]; k++){
            if(state.discard[player][k] == gold || state.discard[player][k] == silver || state.discard[player][k] == copper){
                treasureBefore++;
            }
        }
        for(int k = 0; k < state.discardCount[player]; k++){
            if(state.discard[player][k] == gold || state.discard[player][k] == silver || state.discard[player][k] == copper){
                treasureAfter++;
            }
        }

        if(treasureAfter > treasureBefore){
            printf("Test 3: FAILED-- Incorrect number of treasure cards in discard pile\n\n");
            check = 0;
            break;
        }
    }
    if(check){
        printf("Test 3: PASSED-- Correct number of treasure cards in discard pile\n\n");
    }

    return 0;
}