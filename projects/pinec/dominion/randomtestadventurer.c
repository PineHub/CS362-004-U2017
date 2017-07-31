#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 0



int checkAdventurerCard(int *dTreasure, struct gameState *post, int cPlayer, int* cDrawn, int tHand[10], int* z) {
    struct gameState pre;

    //printf("in check function, cplayer = %d, deck count = %d\n", cPlayer, post->deckCount[cPlayer]);

    memcpy (&pre, post, sizeof(struct gameState));
    int r;
    int i;
    int tHandCount = 0;
    int tDeckDiscardcount = 0;
    int preHandcount = pre.handCount[cPlayer];
    int preDeckcount = pre.deckCount[cPlayer];
    int preDiscardcount = pre.discardCount[cPlayer];

    /*count # of treasure cards in hand before calling adventurer*/
    for(i = 0; i < preHandcount; i++){
        if(pre.hand[cPlayer][i] == copper || pre.hand[cPlayer][i] == silver || pre.hand[cPlayer][i] == gold){

            tHandCount++;
        }

    }

    for(i = 0; i < preDeckcount; i++){
        if(pre.deck[cPlayer][i] == copper || pre.deck[cPlayer][i] == silver || pre.deck[cPlayer][i] == gold){

            tDeckDiscardcount++;
        }

    }

    for(i = 0; i < preDiscardcount; i++){
        if(pre.discard[cPlayer][i] == copper || pre.discard[cPlayer][i] == silver || pre.discard[cPlayer][i] == gold){

            tDeckDiscardcount++;
        }

    }



//  printf("pre: %d, %d, %d, %d\n", pre.numPlayers, pre.handCount[pre.whoseTurn], pre.deckCount[pre.whoseTurn], pre.discardCount[pre.whoseTurn]);

//  printf("post: %d, %d, %d, %d\n", post->numPlayers, post->handCount[post->whoseTurn], post->deckCount[post->whoseTurn], post->discardCount[post->whoseTurn]);
//  printf("number of playas: %d\n", post->numPlayers);

    r = adventurer_card(dTreasure, post, cPlayer, cDrawn, tHand, z);

    //testing goes here to do to pre what we expect adventurer card to do

/*post should have +2 treasures in hand than pre or 1 more treasure if pre has 499 cards or pre should have 500 cards.*/
    int postHandcount = post->handCount[cPlayer];
    int tPostHandcount = 0;
    int postDeckcount = post->deckCount[cPlayer];
    int postDiscardcount = post->discardCount[cPlayer];
    int tPostDeckDiscardcount = 0;
    for(i = 0; i < postHandcount; i++){
        if(post->hand[cPlayer][i] == copper || post->hand[cPlayer][i] == silver || post->hand[cPlayer][i] == gold){

            tPostHandcount++;
        }

    }

    for(i = 0; i < postDeckcount; i++){
        if(post->deck[cPlayer][i] == copper || post->deck[cPlayer][i] == silver || post->deck[cPlayer][i] == gold){

            tPostDeckDiscardcount++;
        }

    }

    for(i = 0; i < postDiscardcount; i++){
        if(post->discard[cPlayer][i] == copper || post->discard[cPlayer][i] == silver || post->discard[cPlayer][i] == gold){

            tPostDeckDiscardcount++;
        }
    }










    //end of pre-tinkering
    assert(r == 0);
#if NOISY_TEST == 1
    printf("checking if postHandcount is  preHandcount + 2 or postHandcount: is 500\n");
#endif
    assert(postHandcount == preHandcount + 2 || postHandcount == 500); //post hand should have +2 hand than pre or post deck should be 500
#if NOISY_TEST == 1
    printf("checking if treasure HandCount: + 2 is treasure PostHandcount:  or preHandcount: is 500) or (preHandcount:  is 499) and treasure PostHandcount: is treasure treasure PostHandcount: + 1))\n");
#endif
    assert((tHandCount + 2 == tPostHandcount) || (preHandcount == 500) || ((preHandcount == 499) && (tHandCount == tPostHandcount + 1)));  //post hand should have +2 treasures than pre or +1 if hand had 499 cards
#if NOISY_TEST == 1
    printf("checking if post deck count + post discard count is pre deck count + pre discard count -2\n");
#endif
    assert(postDeckcount+postDiscardcount == preDeckcount + preDiscardcount -2); //similar reasoning to discard+deck
#if NOISY_TEST == 1
    printf("checking if treasure deck and discard count sum - 2 is equal to treasure post deck and discard count sum or pre hand count is 500 or pre hand count is 499 and the sum of treasure in pre deck and discard count sum less 1 equal the treasure of post's discount and deck treasure\n");
#endif
    assert((tDeckDiscardcount-2 == tPostDeckDiscardcount) || (preHandcount == 500) || ((preHandcount == 499) && (tDeckDiscardcount-1 == tPostDeckDiscardcount)));



    return 0;

}

int main () {

    int i, n, r, p, deckCount, discardCount, handCount;
    int dTreas= 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int numPlayers = 2;
    int thisPlayer = 0;
    int totalAsserts = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing adventurer_card.\n");

    printf ("RANDOM TESTS Adventurer.\n");

    #if NOISY_TEST ==0
        printf("You have NOISY_TEST turned off.  Turn on by setting #define NOISY_TEST = 1\n");
    #endif

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 2000; n++) {

        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }

        int drawnTreasure = 0;
        int cardDrawn;
        int tempHand[MAX_HAND];
        int z = 0; //counter for temp hand
        int x = floor(Random() * 9) + 1; //initializer for seed

        p = floor(Random() * 2);
        r = initializeGame(2, k, x, &G);

        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);

        //printf("in main; deckcount= %d with p= %d.\n", G.deckCount[p], p);



        checkAdventurerCard(&drawnTreasure, &G, p, &cardDrawn, &tempHand[0], &z);




        //printf("run %d was successful \n", n);
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
	  //checkDrawCard(p, &G);
	}
	 }
    }
  }
*/
    return 0;
}

