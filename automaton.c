/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	automaton.c
 * @brief   Tools to manage mere automaton
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include "automaton.h"

void generateTransitionMatrix(Dictionary* newDictionary)
{
	customDictionary = newDictionary;
	int rowIncrement = 0;
	// Memory allocation for the first level of pointer
	transitionMatrix = malloc(STATE_NUMBER*sizeof(InputState*));
	// Browse the rows of the matrix
	for(rowIncrement = 0; rowIncrement < STATE_NUMBER; rowIncrement++)
	{
		// Memory allocation for the second level of pointers
		transitionMatrix[rowIncrement] = malloc(INPUT_STATE_NUMBER*sizeof(InputState));
		int colIncrement = 0;
		// Browse the columns of the matrix
		for(colIncrement = 0; colIncrement < INPUT_STATE_NUMBER; colIncrement++)
		{
			// Assign default value
			transitionMatrix[rowIncrement][colIncrement] = NOT_CORRECT;
		}
	}
	// Assign specific values
	transitionMatrix[0][0] = FOUND_FIRST_ARTICLE;
	transitionMatrix[0][4] = FOUND_FIRST_PROPER_NOUN;
	transitionMatrix[1][1] = FOUND_FIRST_ARTICLE;
	transitionMatrix[1][2] = FOUND_FIRST_NOUN;
	transitionMatrix[2][1] = FOUND_FIRST_NOUN;
	transitionMatrix[2][3] = FOUND_VERB;
	transitionMatrix[3][0] = FOUND_SECOND_ARTICLE;
	transitionMatrix[3][4] = FOUND_SECOND_PROPER_NOUN;
	transitionMatrix[3][5] = FOUND_FINAL_PERIOD;
	transitionMatrix[4][3] = FOUND_VERB;
	transitionMatrix[5][1] = FOUND_SECOND_ARTICLE;
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
	printf("\nAnalysing '%s' :\n",sentence);
	removeOccurences(sentence,',');
	removeOccurences(sentence,';');
	removeOccurences(sentence,':');
	InputState currentState = WAIT_ARTICLE;
	OutputState finishedState = NOT_FINISHED;
	const char delimiter[2] = " ";
	int sentenceLength = strlen(sentence);
	// Process the lack of space before the final period
	if(sentence[sentenceLength-1] == '.' && sentence[sentenceLength-2] != ' ')
	{
		// Copy a space and a period at the end of sentence
		strcpy(sentence+sentenceLength-1, " .");
	}
	char *foundWord;
	// Found the first word
	foundWord = strtok(sentence, delimiter);

	// Browse the other words
	while( foundWord != NULL  && finishedState == NOT_FINISHED)
	{
		// Find the type of the word in the dictionary
		InputType wordType = findTypeOfWord(foundWord);
		// Change the current state based on the transition matrix
		currentState = transitionMatrix[currentState][wordType];
		// Find the finished state based on the current state
		finishedState = actionOfState(currentState);
		// Found the next word
		foundWord = strtok(NULL, delimiter);
	}
	// If the automaton has not processed to a final period
	if(finishedState == NOT_FINISHED || finishedState == FAILURE)
	{
		return(0);
	}
	return(1);
}

InputType findTypeOfWord(char* word)
{
	int i = 0;
	// Browses the dictionary
	for(i = 0; i < baseDictionary.size; i++)
	{
		// If the word is found return its type
		if(!strcmp(baseDictionary.array[i].word,word))
		{
			return(baseDictionary.array[i].inputType);
		}
	}
	// If there is a custom dictionary
	if(customDictionary != NULL)
	{
		// Browses the dictionary
		for(i = 0; i < customDictionary->size; i++)
		{
			// If the word is found return its type
			if(!strcmp(customDictionary->array[i].word,word))
			{
				return(customDictionary->array[i].inputType);
			}
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

void removeOccurences(char* sentence, char charToRemove)
{
	char *read = sentence, *write = sentence;
	//Browse the sentence and copy it without the char to remove
	while (*read)
	{
		*write = *read++;
		write += (*write != charToRemove);
	}
	*write = '\0';
}

InputType charToInputType(char character)
{
	if(character == '0')
	{
		return(ARTICLE);
	}
	else if(character == '1')
	{
		return(ADJECTIVE);
	}
	else if(character == '2')
	{
		return(NOUN);
	}
	else if(character == '3')
	{
		return(VERB);
	}
	else if(character == '4')
	{
		return(PROPER_NOUN);
	}
	else if(character == '5')
	{
		return(PERIOD);
	}
	else
	{
		return(UNKNOWN_WORD);
	}
}
