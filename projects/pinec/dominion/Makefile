CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
#this is for isGameOver()

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
#this is for gainCard()

unittest3: unittest3.c dominion.o rngs.o 
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
#this is for numHandCards()

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
#this is for handCard()

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
#adventurer card

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
#smithy card
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
#village card
all: playdom player testDrawCard testBuyCard badTestDrawCard

runtestadventurer: randomtestadventurer 
	./randomtestadventurer &> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	
runtestcard1: randomtestcard1 
	./randomtestcard1 &> randomtestcard1.out
	gcov -b -c dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	
runtestcard2: randomtestcard2
	./randomtestcard2 &> randomtestcard2.out
	gcov -b -c dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

rununitcardtest1: cardtest1
	./cardtest1 &> cardtest1.out
	gcov -b -c dominion.c >> cardtest1.out
	cat dominion.c.gcov >> cardtest1.out

rununitcardtest2: cardtest2
	./cardtest2 &> cardtest2.out
	gcov -b -c dominion.c >> cardtest2.out
	cat dominion.c.gcov >> cardtest2.out

rununitcardtest3: cardtest3
	./cardtest3 &> cardtest3.out
	gcov -b -c dominion.c >> cardtest3.out
	cat dominion.c.gcov >> cardtest3.out

rununitcardtest4: cardtest4
	./cardtest4 &> cardtest4.out
	gcov -b -c dominion.c >> cardtest4.out
	cat dominion.c.gcov >> cardtest4.out

# mytestresults: run

# run: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2
	# ./unittest1 > unittestresults.out
	# ./unittest2 >> unittestresults.out
	# ./unittest3 >> unittestresults.out
	# ./unittest4 >> unittestresults.out
	# ./cardtest1 >> unittestresults.out
	# ./cardtest2 >> unittestresults.out
	# ./cardtest3 >> unittestresults.out
	# ./cardtest4 >> unittestresults.out
	# ./randomtestadventurer > randomtestadventurer.out
	# ./randomtestcard1 > randomtestcard1.out
	# ./randomtestcard2 > randomtestcard2.out
	# gcov -b -c dominion.c >> unittestresults.out
	# gcov -b -c dominion.c > randomtestresults.out
	# cat dominion.c.gcov >> unittestresults.out
	# cat dominion.c.gcov >> randomtestresults.out

# .PHONY: mytestresults run

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest2 unittest1 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2 unittestresults.out randomtestresults.out randomtestadventurer.out randomtestcard1.out randomtestcard2.out
