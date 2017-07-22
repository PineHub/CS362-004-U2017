#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
    // TODO: rewrite this function
	int c = rand() % (125 + 1 - 32) + 32;
    return c;
}

char *inputString()
{
    // TODO: rewrite this function
	char c;	
	char s[6];
	s[5] = '\0'; 
	int state=0;
	int tcCount = 0;
	while (1){
	tcCount++;
	c = inputChar();
    //printf("S-Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
	if (c == 'r' && state == 0){
		s[state] = c;
		state = 1;
	}
    if (c == 'e' && state == 1){
		s[state] = c;
		state = 2;
	}
    if (c == 's' && state == 2){
		s[state] = c;
		state = 3;
	}
    if (c == 'e'&& state == 3){
		s[state] = c;
		state = 4;
	}
    if (c == 't' && state == 4){
		s[state] = c;
		state = 5;
	}
	if(state == 5 && s[state] == '\0'){
		return s;
	
	}

	}

	
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
