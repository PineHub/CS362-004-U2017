CC:gcc
CFlags=-I.
OBJ = testme.o

%.o: %.c
	$(CC) -c -o $@ $< $(CLAGS)

testme: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean: 
	rm -f testme testme.o


