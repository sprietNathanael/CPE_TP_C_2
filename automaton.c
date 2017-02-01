/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	automaton.c
 * @brief   Tools to manage mere automaton
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include "automaton.h"

void generateTransitionMatrix()
{
	int rowIncrement = 0;
	// Memory allocation for the first level of pointer
	transitionMatrix = malloc(STATE_NUMBER*sizeof(InputState*));
	// Browse the rows of the array
	for(rowIncrement = 0; rowIncrement < STATE_NUMBER; rowIncrement++)
	{
		// Memory allocation for the second level of pointers
		transitionMatrix[rowIncrement] = malloc(INPUT_STATE_NUMBER*sizeof(InputState));
		int colIncrement = 0;
		// Browse the columns of the array
		for(colIncrement = 0; colIncrement < INPUT_STATE_NUMBER; colIncrement++)
		{
			transitionMatrix[rowIncrement][colIncrement] = NOT_CORRECT;
		}
	}
	transitionMatrix[0][0] = FOUND_FIRST_ARTICLE;
	transitionMatrix[0][4] = FOUND_FIRST_PROPER_NOUN;
	transitionMatrix[1][1] = FOUND_FIRST_ARTICLE;
	transitionMatrix[1][2] = FOUND_FIRST_NOUN;
	transitionMatrix[2][1] = FOUND_FIRST_NOUN;
	transitionMatrix[2][3] = FOUND_VERB;
	transitionMatrix[3][1] = FOUND_SECOND_ARTICLE;
	transitionMatrix[3][4] = FOUND_SECOND_PROPER_NOUN;
	transitionMatrix[3][5] = FOUND_FINAL_PERIOD;
	transitionMatrix[4][3] = FOUND_VERB;
	transitionMatrix[5][1] = FOUND_SECOND_NOUN;
	transitionMatrix[5][2] = FOUND_SECOND_NOUN;
	transitionMatrix[6][1] = FOUND_SECOND_NOUN;
	transitionMatrix[6][5] = FOUND_FINAL_PERIOD;
	transitionMatrix[7][5] = FOUND_FINAL_PERIOD;
}

void freeTransitionMatrix()
{
	int rowIncrement;
	// Browse the rows of the  matrix
	for(rowIncrement = 0; rowIncrement < STATE_NUMBER; rowIncrement++)
	{
		// Free the second level of pointers
		free(transitionMatrix[rowIncrement]);
	}
	// Free the first level of pointer
	free(transitionMatrix);

}

int parseSentence(char* sentence)
{
	printf("Analysing '%s' :\n",sentence);
	InputState currentState = WAIT_ARTICLE;
	OutputState finishedState = NOT_FINISHED;
	const char delimiter[2] = " ";
	int sentenceLength = strlen(sentence);
	if(sentence[sentenceLength-1] == '.' && sentence[sentenceLength-2] != ' ')
	{
		strcpy(sentence+sentenceLength-1, " .");
	}
	char *foundWord;
	foundWord = strtok(sentence, delimiter);

	// Browse the other words
	while( foundWord != NULL  && finishedState == NOT_FINISHED)
	{
		InputType wordType = findTypeOfWord(foundWord);
		currentState = transitionMatrix[currentState][wordType];
		finishedState = actionOfState(currentState);
		foundWord = strtok(NULL, delimiter);
	}
	if(finishedState == NOT_FINISHED)
	{
		return(0);
	}
	return(1);
}

InputType findTypeOfWord(char* word)
{
	int i = 0;
	for(i = 0; i < DICTIONARY_SIZE; i++)
	{
		if(!strcmp(dictionary[i].word,word))
		{
			return(dictionary[i].inputType);
		}
	}
	// If the word is not found, return UNKNOWN_WORD type
	return(UNKNOWN_WORD);
}

OutputState actionOfState(InputState state)
{
	// If the sentence is not correct, return FAILURE type
	if(state == NOT_CORRECT)
	{
		return(FAILURE);
	}
	// If the sentence is correct, return SUCCESS type
	else if(state == FOUND_FINAL_PERIOD)
	{
		return(SUCCESS);
	}
	// If the process is not finished yet, return NOT_FINISHED type
	else
	{
		return(NOT_FINISHED);
	}

}
