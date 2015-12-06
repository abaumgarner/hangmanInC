/*
 * Aaron Baumgarner
 */
#ifndef CSCD240HW1_H
#define CSCD240HW1_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define LIMIT 7
#define MAX 100

void printWelcome();
void readNameOne(char * playerOne);
void readNameTwo(char * playerTwo);
void readWord(char * word);
int isWord(char * word);
void changeWord(char * word, int wordLength);
char readGuess();
void removeLtr(char * alpha,char guess);
void setArray(char * result, int len);
int checkGuess(char * alpha,char guess, char * theWord, int length, int attempts, char * result);
void buildMan(int attempts);
int goAgain();
int compare(char * word, char * result);

#endif
