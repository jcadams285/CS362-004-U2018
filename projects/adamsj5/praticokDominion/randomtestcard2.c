#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

//Number of tests 
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

    printf("\nRandom Card Test: Testing the Village card\n");
    printf("----------------------------------------------\n");

    for(int i = 0; i < NUMTESTS; i++){
        //Random number of players
        int numPlayers = randomRange(2, 4);
        int randomSeed = randomRange(1, 1000);
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy};
        //Variables that are not used in smithy card set to 0
        int choice1 = 0;
        int choice2 = 0; 
        int choice3 = 0;
        int bonus = 0;

        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card

        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Randomly assign handPos to a number within a certain value of the current player's hand
        int max_hand = state.handCount[player]-2;
        int handPos = randomRange(0, max_hand);
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(village, choice1, choice2, choice3, &state, handPos, &bonus);

        //Test 1- handcount should have 1 added card - 1 played card
        if (state.handCount[player] != (stateOrg.handCount[player])){
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
        int bonus = 0;


        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Randomly assign handPos to a number within a certain value of the current player's hand
        int max_hand = state.handCount[player]-2;
        int handPos = randomRange(0, max_hand);
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(village, choice1, choice2, choice3, &state, handPos, &bonus); 
        //Playedcard count should have added one
        if (state.playedCardCount != (stateOrg.playedCardCount + 1)){
            printf("Test 2: FAILED-- Incorrect number of played cards\n");
            check = 0;
            break;
        }
    }
    if(check){
        printf("Test 2: PASSED-- Correct number of played cards\n");
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
        int bonus = 0;


        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Randomly assign handPos to a number within a certain value of the current player's hand
        int max_hand = state.handCount[player]-2;
        int handPos = randomRange(0, max_hand);
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(village, choice1, choice2, choice3, &state, handPos, &bonus);
        //Deck card pile should have one less
        if (state.deckCount[player] != (stateOrg.deckCount[player] - 1)){
            printf("Test 3: FAILED-- Incorrect number of cards in deck pile\n");
            check = 0;
            break;
        }
    }
    if(check){
        printf("Test 3: PASSED-- Correct number of cards in deck pile\n");
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
        int bonus = 0;


        //Start up game
        initializeGame(numPlayers, k, randomSeed, &state);
        //Make up random variables in gameState that are used in adventurer card
        randomGameState(&state, numPlayers);
        //Find out whose turn it is
        int player = state.whoseTurn;
        //Randomly assign handPos to a number within a certain value of the current player's hand
        int max_hand = state.handCount[player]-2;
        int handPos = randomRange(0, max_hand);
        //Save gameState before card is played
        stateOrg = state;
        //Play card
        cardEffect(village, choice1, choice2, choice3, &state, handPos, &bonus);
        //2 action points should have been added - 1 that was taken by playing the card
        if (state.numActions != (stateOrg.deckCount[player] + 1)){
            printf("Test 4: FAILED-- Incorrect number of action points\n\n");
            check = 0;
            break;
        }
    }
    if(check){
        printf("Test 4: PASSED-- Correct number of action points\n\n");
    }

    return 0;
}