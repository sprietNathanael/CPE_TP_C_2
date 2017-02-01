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
#include "file.h"

#define TEST_NUMBER 13
#define TEST_MAX_SIZE 1000

int main()
{
	Dictionary* customDictionary = NULL;
	// Read a file
	customDictionary = readDictionary("./dictionary.txt");
	// Check if the file exists
	if(customDictionary == NULL)
	{
		printf("The file './dictionary.txt' does not exitst\n");
	}

	// Initialise automaton
	generateTransitionMatrix(customDictionary);

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
	strcpy(test[9],"les loup gris court.");
	strcpy(test[10],".");
	strcpy(test[11],"");
	strcpy(test[12],"le joli chat joue");
	strcpy(test[13],"le joli chat miaule.");

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

	// Free the custom dictionary if it exists
	if(customDictionary != NULL)
	{
		free(customDictionary->array);
		free(customDictionary);
	}
	return 0;
}
