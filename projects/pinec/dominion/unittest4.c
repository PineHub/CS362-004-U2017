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
	printf("prememset: no seg fault.\n");
	memset(&G, 23, sizeof(struct gameState)); //clear game state
	r = initializeGame(numPlayer, k, seed, &G);  //init new game
	p = 1;
	//G.handCount[p] = handCount; //set number of cards on hand

    printf ("TESTING handCard():\n");
    //for (p = 0; p < numPlayer; p++)
    //{
		G.whoseTurn=p;
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
				G.handCount[p]= handCount;
				G.hand[p][handCount] = handCount+1;
				
#if (NOISY_TEST == 1)
                printf("Testing player with %d card(s) in hand.\n", G.handCount[p]);
				printf("Expect: %d, handcard() output: %d.\n", G.hand[1][handCount], handCard(handCount, &G));
#endif
                assert(handCard(handCount, &G) == G.hand[1][handCount]); // check if the card in hand is correct
            }
      //  }

    printf("All tests passed!\n");

    return 0;
}
