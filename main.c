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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
int main(int argc, char const *argv[])
{
	Dictionary* customDictionary = NULL;
	if(argc > 1)
	{
		// Read a file
		customDictionary = readDictionary((char*)argv[1]);
		// Check if the file exists
		if(customDictionary == NULL)
		{
			printf("The file '%s' does not exitst\n",argv[1]);
		}
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
			printf(ANSI_COLOR_GREEN"The sentence is correct"ANSI_COLOR_RESET"\n");
		}
		else
		{
			printf(ANSI_COLOR_RED"The sentence is not correct"ANSI_COLOR_RESET"\n");
		}
	}

	char user_entry[TEST_MAX_SIZE];
	int userEntryLoop = 1;
	do
	{
		printf("\n\n\nEntrez une phrase à analyser  ('quit' pour quitter) :\n");
		scanf("%[^\n]%*c", user_entry);
		if(strcmp(user_entry,"quit"))
		{
			if(parseSentence(user_entry))
			{
				printf(ANSI_COLOR_GREEN"The sentence is correct"ANSI_COLOR_RESET"\n");
			}
			else
			{
				printf(ANSI_COLOR_RED"The sentence is not correct"ANSI_COLOR_RESET"\n");
			}
		}
		else
		{
			userEntryLoop = 0;
		}
	} while(userEntryLoop);



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
