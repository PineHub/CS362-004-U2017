/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int myAssert(int newValue, int expected){

	if(newValue == expected){

		printf("new value = %d, expected value = %d PASSED!\n", newValue, expected);
		return 0;
		}
	else{
		printf("new value = %d, expected value = %d FAILED!\n", newValue, expected);
		return 1;
		}

}


int myAssert2(int newValue, int expected){

	if(newValue != expected){

		printf("new value = %d, expected value = %d PASSED!\n", newValue, expected);
		return 0;
		}
	else{
		printf("new value = %d, unexpected value = %d FAILED!\n", newValue, expected);
		return 1;
		}

}


int main() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int drawnTreasure = 0;
	int cardDrawn;
	int tempHand[MAX_HAND];
	int z = 0; //counter for temp hand
	int totalAsserts = 0;


	
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: estate cards at position 0, 1, 7, all others copper ------
	printf("TEST 1: TEST 1: estate cards at position 0, 1, 7, all others copper.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	adventurer_card(&drawnTreasure, &testG, thisPlayer, &cardDrawn, &tempHand[0], &z);
	
	printf("new vs expected deck count:\n");
	totalAsserts += myAssert(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 2);
	printf("new vs expected hand count:\n");
	totalAsserts += myAssert(testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
	printf("new vs expected discardCount:\n");
	totalAsserts += myAssert(testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + 0);
    
	// ----------- TEST 2: no copper cards in deck, 2 coppers in discard ------------
	printf("TEST 2: no copper cards in deck, 2 coppers in discard\n");

	// copy the game state to a test case
	
	for(i = 0; i <= MAX_DECK; i++){

		if (G.deck[thisPlayer][i] > 3 || G.deck[thisPlayer][i] < 7){

		G.deck[thisPlayer][i] = 1;
		
		}

	}

	gainCard(4, &G, 0, thisPlayer);
	gainCard(4, &G, 0, thisPlayer);

	memcpy(&testG, &G, sizeof(struct gameState));

	adventurer_card(&drawnTreasure, &testG, thisPlayer, &cardDrawn, &tempHand[0], &z);


	printf("new vs expected deck count:\n");
	totalAsserts += myAssert(testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("new vs expected hand count:\n");
	totalAsserts += myAssert(testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
	printf("new vs expected discardCount:\n");
	totalAsserts += myAssert(testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	
	
	
	if(totalAsserts == 0){
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}

	else{
	printf("\n>>>>>FAILURE: found %d failures %s<<<<<<\n\n", totalAsserts, TESTCARD);	 }

	return 0;
}


