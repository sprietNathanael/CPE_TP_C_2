/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	main.c
 * @brief   Create an automaton to syntatically chek a simple sentence
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "automaton.h"

#define TEST_NUMBER 13
#define TEST_MAX_SIZE 1000

int main()
{
	// Initialise automaton
	generateTransitionMatrix();

	// Make an array of string to test
	char test[TEST_NUMBER][TEST_MAX_SIZE];
	strcpy(test[0],"le joli chat joue.");
	strcpy(test[1],"le ,joli chat ; joue.");
	strcpy(test[2],"la grosse souris verte mange le joli petit chat blanc.");
	strcpy(test[3],"la grosse souris verte mange Jean.");
	strcpy(test[4],"la grosse souris verte mange le joli petit chat blanc.");
	strcpy(test[5],"Jean joue.");
	strcpy(test[6],"Jean mange Martin.");
	strcpy(test[7],"Jean mange le chat.");
	strcpy(test[8],"la verte souris grosse petit mange le blanc verte chat petit.");
	strcpy(test[9],".");
	strcpy(test[10],"");
	strcpy(test[11],"le joli chat joue");
	strcpy(test[12],"le joli chat miaule.");

	// Test the array
	int i = 0;
	for(i = 0; i < TEST_NUMBER; i++)
	{
		if(parseSentence(test[i]))
		{
			printf("The sentence is correct\n");
		}
		else
		{
			printf("The sentence is not correct\n");
		}
	}

	char user_entry[TEST_MAX_SIZE];
	printf("\n\n\nEntrez une phrase à analyser :\n");
	scanf("%[^\n]s", user_entry);
	if(parseSentence(user_entry))
	{
		printf("The sentence is correct\n");
	}
	else
	{
		printf("The sentence is not correct\n");
	}



	// Free the automaton
	freeTransitionMatrix();
	return 0;
}
