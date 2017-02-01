/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	automaton.c
 * @brief   Tools to manage mere automaton
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include "automaton.h"

InputState** generateTransitionMatrix()
{
	int rowIncrement = 0;
	InputState** array;
	// Memory allocation for the first level of pointer
	array = malloc(STATE_NUMBER*sizeof(InputState*));
	// Browse the rows of the array
	for(rowIncrement = 0; rowIncrement < STATE_NUMBER; rowIncrement++)
	{
		// Memory allocation for the second level of pointers
		array[rowIncrement] = malloc(INPUT_STATE_NUMBER*sizeof(InputState));
		int colIncrement = 0;
		// Browse the columns of the array
		for(colIncrement = 0; colIncrement < INPUT_STATE_NUMBER; colIncrement++)
		{
			array[rowIncrement][colIncrement] = NOT_CORRECT;
		}
	}
	array[0][0] = FOUND_FIRST_ARTICLE;
	array[0][4] = FOUND_FIRST_PROPER_NOUN;
	array[1][1] = FOUND_FIRST_ARTICLE;
	array[1][2] = FOUND_FIRST_NOUN;
	array[2][1] = FOUND_FIRST_NOUN;
	array[2][3] = FOUND_VERB;
	array[3][1] = FOUND_SECOND_ARTICLE;
	array[3][4] = FOUND_SECOND_PROPER_NOUN;
	array[3][5] = FOUND_FINAL_PERIOD;
	array[4][3] = FOUND_VERB;
	array[5][1] = FOUND_SECOND_NOUN;
	array[5][2] = FOUND_SECOND_NOUN;
	array[6][1] = FOUND_SECOND_NOUN;
	array[6][5] = FOUND_FINAL_PERIOD;
	array[7][5] = FOUND_FINAL_PERIOD;
	return(array);
}

void freeTransitionMatrix(InputState** matrix)
{
	int rowIncrement;
	// Browse the rows of the  matrix
	for(rowIncrement = 0; rowIncrement < STATE_NUMBER; rowIncrement++)
	{
		// Free the second level of pointers
		free(matrix[rowIncrement]);
	}
	// Free the first level of pointer
	free(matrix);

}

int parseSentence(char* sentence)
{
	const char delimiter[2] = " ";
	char *foundWord;
	foundWord = strtok(sentence, delimiter);

	/* walk through other tokens */
	while( foundWord != NULL )
	{
	  printf( "%s\n", foundWord);

	  foundWord = strtok(NULL, delimiter);
	}
	return(1);
}
