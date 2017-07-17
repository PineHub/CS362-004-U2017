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

    printf ("TESTING gainCard():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.handCount[p] = handCount;                 // set the number of cards on hand
	int chosenSupplyCard = rand() % (16+1-0)+0;
	int prevSupplyQ = supplyCount(chosenSupplyCard, &G);
#if (NOISY_TEST == 1)
	printf("Testing Supply with %d cards of type %d\n", prevSupplyQ, chosenSupplyCard); 

#endif
	gainCard(chosenSupplyCard, &G, 0, 1);
	printf("New supply of %d-cards is %d, expecting %d\n\n", chosenSupplyCard, supplyCount(chosenSupplyCard, &G), prevSupplyQ-1);
	assert(prevSupplyQ-1 == supplyCount(chosenSupplyCard, &G));

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.handCount[p] = handCount;                 // set the number of cards on hand
	chosenSupplyCard = rand() % (16+1-0)+0;
	int prevDiscardQ = G.discardCount[1];
	int prevHandQ = G.handCount[1];
	int prevDeckQ = G.deckCount[1];

	int prevTestCardQ = 0;
	for (i = 0; i < G.deckCount[1]; i++){
		if(G.discard[1][i] == chosenSupplyCard) prevTestCardQ++;
	}

	int newTestCardQ = 0;


#if (NOISY_TEST == 1)
	printf("Testing if player adds card#%d to discard pile, with current quantity %d, current total of cards in discard pile %d, current cards in hand %d, and current cards in deck %d.\n", chosenSupplyCard, prevTestCardQ, prevDiscardQ, prevHandQ, prevDeckQ);
#endif
	gainCard(chosenSupplyCard, &G, 0, 1);

	for (i=0; i < G.discardCount[1]; i++){
		if(G.discard[1][i] == chosenSupplyCard) newTestCardQ++;
	}

	printf("Discard pile quantity for player 1 of %d-cards is %d, expecting %d\n, discard quantity is %d, expecting %d\n, hand quantity is %d, expecting %d\n, deck quantity %d, expecting %d.\n\n", chosenSupplyCard, newTestCardQ, prevTestCardQ+1, G.discardCount[1], prevDiscardQ+1, G.handCount[1], prevHandQ, G.deckCount[1], prevDeckQ);

	assert(newTestCardQ == prevTestCardQ+1);
	assert(G.discardCount[1] == prevDiscardQ+1);
	assert(G.handCount[1] == prevHandQ);
	assert(G.deckCount[1] == prevDeckQ);


	chosenSupplyCard = rand() % (16+1-0)+0; 
	chosenSupplyCard = rand() % (16+1-0)+0;
	prevDiscardQ = G.discardCount[1];
	prevHandQ = G.handCount[1];
	prevDeckQ = G.deckCount[1];
	prevTestCardQ = 0;
	for (i = 0; i < G.deckCount[1]; i++){
		if(G.deck[1][i] == chosenSupplyCard) prevTestCardQ++;
	}
	newTestCardQ = 0;


#if (NOISY_TEST == 1)
	printf("Testing if player adds card#%d to deck, with current quantity %d, current total of cards in deck %d, current cards in hand %d, and current cards in discard %d.\n", chosenSupplyCard, prevTestCardQ, prevDiscardQ, prevHandQ, prevDiscardQ);
#endif
	gainCard(chosenSupplyCard, &G, 1, 1);

	for (i=0; i < G.deckCount[1]; i++){
		if(G.deck[1][i] == chosenSupplyCard) newTestCardQ++;
	}

	printf("Deck quantity for player 1 of %d-cards is %d, expecting %d\n, discard quantity is %d, expecting %d\n, hand quantity is %d, expecting %d\n, deck quantity %d, expecting %d.\n\n", chosenSupplyCard, newTestCardQ, prevTestCardQ+1, G.discardCount[1], prevDiscardQ, G.handCount[1], prevHandQ, G.deckCount[1], prevDeckQ+1);

	assert(newTestCardQ == prevTestCardQ+1);
	assert(G.discardCount[1] == prevDiscardQ);
	assert(G.handCount[1] == prevHandQ);
	assert(G.deckCount[1] == prevDeckQ+1);

	chosenSupplyCard = rand() % (16+1-0)+0; 
	chosenSupplyCard = rand() % (16+1-0)+0;
	prevDiscardQ = G.discardCount[1];
	prevHandQ = G.handCount[1];
	prevDeckQ = G.deckCount[1];
	prevTestCardQ = 0;
	for (i = 0; i < G.handCount[1]; i++){
		if(G.hand[1][i] == chosenSupplyCard) prevTestCardQ++;
	}
	newTestCardQ = 0;


#if (NOISY_TEST == 1)
	printf("Testing if player adds card#%d to deck, with current quantity %d, current total of cards in deck %d, current cards in hand %d, and current cards in discard %d.\n", chosenSupplyCard, prevTestCardQ, prevDiscardQ, prevHandQ, prevDiscardQ);
#endif
	gainCard(chosenSupplyCard, &G, 2, 1);

	for (i=0; i < G.handCount[1]; i++){
		if(G.hand[1][i] == chosenSupplyCard) newTestCardQ++;
	}

	printf("Deck quantity for player 1 of %d-cards is %d, expecting %d\n, discard quantity is %d, expecting %d\n, hand quantity is %d, expecting %d\n, deck quantity %d, expecting %d.\n\n", chosenSupplyCard, newTestCardQ, prevTestCardQ+1, G.discardCount[1], prevDiscardQ, G.handCount[1], prevHandQ+1, G.deckCount[1], prevDeckQ);

	assert(newTestCardQ == prevTestCardQ+1);
	assert(G.discardCount[1] == prevDiscardQ);
	assert(G.handCount[1] == prevHandQ+1);
	assert(G.deckCount[1] == prevDeckQ);
	

    printf("All tests passed!\n");

    return 0;
}
