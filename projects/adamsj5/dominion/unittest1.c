#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"

int main (int argc, char** argv) {
	struct gameState state;
  	// int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
   //         sea_hag, tribute, smithy};
    int player = 0;
    int bonus = 0;
    // int numOfPlayers = 2;
    // int s = 5;

    //test 1: test for player holding 0 cards
    state.handCount[player] = 0;

    printf("Unit Test #1: Testing the updateCoins function\n");
    printf("----------------------------------------------\n");

    updateCoins(player, &state, bonus);

    if (state.coins == 0){
    	printf("Test 1: PASSED-- %d coins counted == 0 coins expected\n", state.coins);
    }
    else {
    	printf("Test 1: FAILED-- %d coins counted != 0 coins expected\n", state.coins);
    }

    //test 2: test for copper card working
    state.handCount[player] = 1;
    state.hand[player][0] = copper;

    updateCoins(player, &state, bonus);

    if (state.coins == 1){
    	printf("Test 2: PASSED-- %d coin counted == 1 coin expected\n", state.coins);
    }
    else {
    	printf("Test 2: FAILED-- %d coins counted != 1 coin expected\n", state.coins);
    }

    //test 3: test for silver card working
    state.handCount[player] = 1;
    state.hand[player][0] = silver;

    updateCoins(player, &state, bonus);

    if (state.coins == 2){
    	printf("Test 3: PASSED-- %d coins counted == 2 coins expected\n", state.coins);
    }
    else {
    	printf("Test 3: FAILED-- %d coins counted != 2 coins expected\n", state.coins);
    }

    //test 4: test for gold card working
    state.handCount[player] = 1;
    state.hand[player][0] = gold;

    updateCoins(player, &state, bonus);

    if (state.coins == 3){
    	printf("Test 4: PASSED-- %d coins counted == 3 coins expected\n", state.coins);
    }
    else {
    	printf("Test 4: FAILED-- %d coins counted != 3 coins expected\n", state.coins);
    }

    //test 5: test for hand with one of each coin card
    state.handCount[player] = 3;
    state.hand[player][0] = gold;
    state.hand[player][1] = silver;
    state.hand[player][2] = copper;

    updateCoins(player, &state, bonus);

    if (state.coins == 6){
    	printf("Test 5: PASSED-- %d coins counted == 6 coins expected\n", state.coins);
    }
    else {
    	printf("Test 5: FAILED-- %d coins counted != 6 coins expected\n", state.coins);
    }

    //test 6: test for hand with one of each coin card mixed in with kingdom cards
    state.handCount[player] = 5;
    state.hand[player][0] = gold;
    state.hand[player][1] = silver;
    state.hand[player][2] = copper;
    state.hand[player][3] = gardens;
    state.hand[player][4] = village;

    updateCoins(player, &state, bonus);

    if (state.coins == 6){
    	printf("Test 6: PASSED-- %d coins counted == 6 coins expected\n", state.coins);
    }
    else {
    	printf("Test 6: FAILED-- %d coins counted != 6 coins expected\n", state.coins);
    }

    //test 7: test for hand with 0 coin cards but has kingdom cards
    state.handCount[player] = 5;
    state.hand[player][0] = gardens;
    state.hand[player][1] = village;
    state.hand[player][2] = mine;
    state.hand[player][3] = gardens;
    state.hand[player][4] = village;

    updateCoins(player, &state, bonus);

    if (state.coins == 0){
    	printf("Test 7: PASSED-- %d coins counted == 0 coins expected\n", state.coins);
    }
    else {
    	printf("Test 7: FAILED-- %d coins counted != 0 coins expected\n", state.coins);
    }

    //test 8: test for bonus coins
    bonus = 3;
    state.handCount[player] = 5;
    state.hand[player][0] = gardens;
    state.hand[player][1] = village;
    state.hand[player][2] = mine;
    state.hand[player][3] = gardens;
    state.hand[player][4] = village;

    updateCoins(player, &state, bonus);

    if (state.coins == 3){
    	printf("Test 8: PASSED-- %d coins counted == 3 coins expected\n\n", state.coins);
    }
    else {
    	printf("Test 8: FAILED-- %d coins counted != 3 coins expected\n\n", state.coins);
    }
    return 0;
}

