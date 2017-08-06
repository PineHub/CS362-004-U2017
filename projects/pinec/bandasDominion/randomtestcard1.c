#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 0

int checkSmithyCard(int p, struct gameState *post, int hPos) {
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    int r;

#if NOISY_TEST == 1
      printf ("smithyCard PRE: p %d HC %d DeC %d DiC %d\n",
    	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
#endif



    r = smithyCard(p, post, hPos);

#if NOISY_TEST == 1
    printf ("smithyCard POST: p %d HC %d DeC %d DiC %d\n", p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
#endif


    int i;

    for (i = 0; i<3; i++) {
        /*if (pre.deckCount[p] > 0) {
            pre.discardCount[p]++;
            pre.discard[p][pre.discardCount[p] - 1] = pre.deck[p][pre.deckCount[p] - 1];
            pre.deckCount[p]--;
        } else if (pre.discardCount[p] > 0) {
            memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
            memcpy(pre.discard[p], post->discard[p], sizeof(int) * pre.discardCount[p]);
            pre.discard[p][post->discardCount[p] - 1] = post->discard[p][post->discardCount[p] - 1];
            pre.discardCount[p]++;
            pre.deckCount[p] = pre.discardCount[p] - 1;
            pre.discardCount[p] = 0;
        }*/
        if (pre.deckCount[p] > 0) {
            pre.handCount[p]++;
            pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p]-1];
            pre.deckCount[p]--;
        } else if (pre.discardCount[p] > 0) {
            memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
            memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
            pre.hand[p][post->handCount[p]-1] = post->hand[p][post->handCount[p]-1];
            pre.handCount[p]++;
            pre.deckCount[p] = pre.discardCount[p]-1;
            pre.discardCount[p] = 0;
        }

    }
    discardCard(hPos, p, &pre, 0);


#if NOISY_TEST == 1
    printf ("smithyCard --new-- PRE: p %d HC %d DeC %d DiC %d\n",
            p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
#endif

    assert (r == 0);

    assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);  //both pre and post are equal?
}

int main () {

    int i, n, r, p, deckCount, discardCount, handCount;

    int handpos = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing SmithyCard.\n");

    printf ("RANDOM TESTS.\n");

    #if NOISY_TEST ==0
        printf("You have NOISY_TEST turned off.  Turn on by setting #define NOISY_TEST = 1\n");
    #endif

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }

        int x = floor(Random() * 9) + 1; //initializer for seed

        p = floor(Random() * 2);
        r = initializeGame(2, k, x, &G);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        checkSmithyCard(p, &G, handpos);

        handpos = 0;
    }

    printf ("ALL TESTS OK\n");


/*

printf ("SIMPLE FIXED TESTS.\n");
    for (p = 0; p < 2; p++) {
        for (deckCount = 0; deckCount < 5; deckCount++) {
            for (discardCount = 0; discardCount < 5; discardCount++) {
                for (handCount = 0; handCount < 5; handCount++) {
                    memset(&G, 23, sizeof(struct gameState));
                    r = initializeGame(2, k, 1, &G);
                    G.deckCount[p] = deckCount;
                    memset(G.deck[p], 0, sizeof(int) * deckCount);
                    G.discardCount[p] = discardCount;
                    memset(G.discard[p], 0, sizeof(int) * discardCount);
                    G.handCount[p] = handCount;
                    memset(G.hand[p], 0, sizeof(int) * handCount);
                    checkSmithyCard(p, handpos, &G);
                }
            }
        }
    }

*/

    return 0;
}
