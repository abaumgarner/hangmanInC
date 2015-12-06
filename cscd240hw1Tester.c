/*
 * Aaron Baumgarner
 * The one thing that I was not able to figure out was to prevent the user from guessing the same letter twice.
 * It is probably something simple. I just can't think of it right now.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "cscd240hw1.h"

int main()
{
	char playerOne[MAX];
	char playerTwo[MAX];
	char word[MAX];
	char result[MAX];
	//char alpha[27];
	char guess;
	int attempts;
	int wordLength;

	do
	{
		printWelcome();
		attempts=0;	
		printf("\n\n");		
		readNameOne(playerOne);						
		readWord(word);
		char alpha[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		wordLength= strlen(word);
		changeWord(word, wordLength);
		setArray(result, wordLength);
		readNameTwo(playerTwo);
		printf("%s\n",alpha);
 
		do
		{
			printf("%s\n", result);
			guess = readGuess();
			removeLtr(alpha, guess);
			printf("%s\n",alpha);
			attempts=checkGuess(alpha,guess, word, wordLength, attempts, result);
		}while(compare(word, result) && attempts < LIMIT);
		printf("%s\n", result);
	}while(goAgain()); 						

	return 0;

} // end main
