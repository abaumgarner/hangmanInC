/*
 * Aaron Baumgarner 
 */
#include "cscd240hw1.h"

void printWelcome()
{
	printf("\t\tWelcome to Hangman\n");
	printf("Player one enters their name (single name) and then player one enters a\n");
	printf("single word for the other player to guess. (There will be no spaces in the word)\n");
	printf("Player 2 then enters their name (single name). Player 2 has a maximum of 7 tries to guess the\n");
	printf("word. If player 2 guesses the word in 7 or less tries, a message of congratulations is displayed. If\n");
	printf("the word is not guessed after 7 tries, a losing message is displayed along with what the correct\n");
	printf("word was.\n\n");
	printf("The option to play the game again is then given (y/n)\n");
}//end printWelcome

void readNameOne(char * playerOne)
{
	printf("\tPlayer One\n");
	printf("Please enter your name: ");
	scanf("%s",playerOne);
	printf("\tWelcome %s\n",playerOne);
}//end readNameOne

void readWord(char * word)
{
	do
	{
		printf("Please enter a single word to be guessed: ");
		scanf(" %s",word);
		if(isWord(word))
			printf("Please enter only letters.\n");
	}while(isWord(word));
}//end readWord

int isWord(char * word)
{
	while(*word !='\0')
		{
			if((*word>='A'&&*word<='Z') || (*word>='a'&&*word<='z'))
				word++;
			else
				return 1;
		}
	return 0;
	/*
	int len=strlen(word);
	int i;
	for(i=0;i<len-1;i++)
		if(isalpha(*(word+i)))
			return 1;
	return 0;
	*/
}//end isWord
void changeWord(char * word, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
			*(word+i)=tolower(*(word+i));
	}
}//end changeWord

void setArray(char * result, int len)
{
	int i;
	for(i=0;i<len;i++)
		*(result+i)='-';
}//end setArray

void readNameTwo(char * playerTwo)
{
	printf("\tPlayer Two\n");
	printf("Please enter your name: ");
	scanf("%s",playerTwo);
	printf("\tWelcome %s\n",playerTwo);
}//end readNameTwo

char readGuess()
{
	char ltr;
	printf("Enter a letter: ");
	scanf(" %c", &ltr);
	return ltr;
}//end readGuess

void removeLtr(char * alpha,char guess)
{
	int i;
	for(i=0;i<26;i++)
		if(*(alpha+i) == guess)
			*(alpha+i)=' ';
}//end removeLtr

int checkGuess(char * alpha,char guess, char * theWord, int length, int attempts, char * result)
{
		int i;
		int contains=1;
		
		for(i=0;i<length;i++)
		{
				if(guess == *(theWord+i))
				{
					contains=0;
					*(result+i)=guess;
				}
		}
		if(contains == 1)
		{
			attempts++;
			printf("\n");
			buildMan(attempts);
			printf("Incorrect guess. You have %d tries left.", LIMIT-attempts);
		}
		printf("\n");
		return attempts;
}//end checkGuess

void buildMan(int attempts)
{
	if(attempts==1)
	{
		printf("_________\n");
		printf("|/      |\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==2)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==3)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");
		printf("|\t |\n");
		printf("|\t |\n");
		printf("|\n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==4)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");;
		printf("|      --|\n");
		printf("|\t |\n");
		printf("|\n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==5)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");;
		printf("|      --|--\n");
		printf("|\t |\n");
		printf("|\n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==6)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");;
		printf("|      --|--\n");
		printf("|\t |\n");
		printf("|       | \n");
		printf("|\n");
		printf("|___\n");
	}
	else if(attempts==7)
	{
		printf("__________\n");
		printf("|/       |\n");
		printf("|\t(_)\n");;
		printf("|      --|--\n");
		printf("|\t |\n");
		printf("|       | |\n");
		printf("|\n");
		printf("|___\n");
	}
}//end buildMan

int goAgain()
{
	int y;
	int n;
	char S[100];
	do
	{
		printf("Would you like to play again? (y/n): ");
                scanf("%s",S);
                y = strncmp(S,"y",100);
                n = strncmp(S,"n",100);
        }while(y !=0 && n !=0);

	if(y==0)
		return 1;
	else
	{
		printf("Thank you for playing\n");
		return 0;
	}
}//end goAgain

int compare(char * word, char * result)
{
	int i;
	int len=strlen(word);
	for(i=0;i<len;i++)
	{
		if(*(result+i) != *(word+i))
			return 1;
	}
	return 0;
}//end compare
