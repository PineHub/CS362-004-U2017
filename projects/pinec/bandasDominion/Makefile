CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

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


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest2 unittest1 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2 unittestresults.out randomtestresults.out randomtestadventurer.out randomtestcard1.out randomtestcard2.out
