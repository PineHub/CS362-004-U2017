#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	srand(time(NULL));
	int numTests = 500; //number of tests to run
	int firstCard;
	int secondCard;
	int thirdCard;

    printf ("TESTING isGameOver():\n");
	
	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
#if (NOISY_TEST == 1)
	printf("Test if all supply stacks are 0.\n");
#endif
	for (i = 0; i < minion; i++){

		G.supplyCount[i] = 0;
	};
#if (NOISY_TEST == 1)
	printf("isGameOver() = %d, expected = 1\n", isGameOver(&G));
#endif
	assert(isGameOver(&G) == 1); //check if the game ended after all supply stacks depleted


	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
#if (NOISY_TEST == 1)
	printf("Test if all supply stacks are have 1 card.\n");
#endif
	for (i = 0; i < minion; i++){

		G.supplyCount[i] = 1;
	};
#if (NOISY_TEST == 1)
	printf("isGameOver() = %d, expected = 0\n", isGameOver(&G));
#endif
	assert(isGameOver(&G) == 0); //check if the game didn't end after all supply stacks have >0 cards

	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
#if (NOISY_TEST == 1)
	printf("Test if province supply have 0 cards.\n");
#endif
	G.supplyCount[province] = 0;
#if (NOISY_TEST == 1)
	printf("isGameOver() = %d, expected = 1\n", isGameOver(&G));
#endif
	assert(isGameOver(&G) == 1);  //check if game ended after province cards have 0 supply. 


	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
#if (NOISY_TEST == 1)
	printf("Test if 3 random supply piles have 0 cards %d times.\n", numTests);
#endif

	for(i = 0; i < numTests; i++){ //test several times with 3 different empty supply stacks to see if the game is over.
	
	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
	firstCard = rand() % (16 + 1 - 0) + 0;
	secondCard = rand() % (16 + 1 -0) + 0;
	while(secondCard == firstCard){

		secondCard = rand() % (16+ 1 - 0) + 0;
	}
	thirdCard = rand() % (16+ 1 - 0) + 0;
	while(thirdCard == firstCard || thirdCard == secondCard){

		thirdCard = rand() % (16+ 1 - 0) + 0;
	}
	G.supplyCount[firstCard] = 0;
	G.supplyCount[secondCard] = 0;
	G.supplyCount[thirdCard] = 0;

	/*printf("firstCard = %d\n", firstCard);
	printf("secondCard = %d\n", secondCard);
	printf("thirdCard = %d\n", thirdCard);
	*/
	assert(isGameOver(&G) == 1); //check if game ended after 3 cards have 0 supply
	}
#if (NOISY_TEST == 1)
	printf("isGameOver() = %d, expected = 1\n", isGameOver(&G));
#endif
	
#if (NOISY_TEST == 1)
	printf("Test if 2 random supply piles have 0 cards %d times.\n", numTests);
#endif
	for(i = 0; i < numTests; i++){ //test several times with 2 different empty supply stacks to see if the game is not over.
	
	memset(&G, 23, sizeof(struct gameState)); //clear the game state
	r = initializeGame(numPlayer, k, seed, &G); //initialize a new game
	firstCard = rand() % (16 + 1 - 0) + 0;
	while(firstCard == province){

		firstCard = rand() % (16+1 -0) + 0;
	}

	secondCard = rand() % (16 + 1 -0) + 0;
	while(secondCard == firstCard || secondCard == province){

		secondCard = rand() % (16+ 1 - 0) + 0;
	}

	G.supplyCount[firstCard] = 0;
	G.supplyCount[secondCard] = 0;

	/*printf("firstCard = %d\n", firstCard);
	printf("secondCard = %d\n", secondCard);
	printf("thirdCard = %d\n", thirdCard);
	*/
	assert(isGameOver(&G) == 0); //check if game ended after only 2 cards have 0 supply
	}
#if (NOISY_TEST == 1)
	printf("isGameOver() = %d, expected = 0\n", isGameOver(&G));
#endif

    printf("All tests passed!\n");

    return 0;
}
