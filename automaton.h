/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	automaton.h
 * @brief   Tools to manage sentence automaton
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef AUTOMATON_H
#define AUTOMATON_H


/*
***************************** Constants *************************
*/
#define STATE_NUMBER 10
#define INPUT_STATE_NUMBER 7
#define WORD_MAX_SIZE 255

#define DICTIONARY_SIZE 19

/*
 ***************************** Enumerations *************************
*/

/**
 * @brief      The different input states
 */
enum inputState
{
	WAIT_ARTICLE=0,
	FOUND_FIRST_ARTICLE=1,
	FOUND_FIRST_NOUN=2,
	FOUND_VERB=3,
	FOUND_FIRST_PROPER_NOUN=4,
	FOUND_SECOND_ARTICLE=5,
	FOUND_SECOND_NOUN=6,
	FOUND_SECOND_PROPER_NOUN=7,
	NOT_CORRECT=8,
	FOUND_FINAL_PERIOD=9
};
/**
* @brief      A type defined over the inputState enumeration
*/
typedef enum inputState InputState;

/**
 * @brief      The different output states
 */
enum outputState
{
	NOT_FINISHED=-1,
	FAILURE=0,
	SUCCESS=1
};
/**
* @brief      A type defined over the outputState enumeration
*/
typedef enum outputState OutputState;

/**
 * @brief      The different input types
 */
enum inputType
{
	ARTICLE=0,
	ADJECTIVE=1,
	NOUN=2,
	VERB=3,
	PROPER_NOUN=4,
	PERIOD=5,
	UNKNOWN_WORD=6
};
/**
* @brief      A type defined over the inputType enumeration
*/
typedef enum inputType InputType;

/*
***************************** Structures *************************
*/

/**
 * @brief      Represents a dictionary entry
 */
struct dictionaryEntry
{
	char word[WORD_MAX_SIZE];/*!< The word itself */
	InputType inputType;/*!< The type of the word */
};
/**
* @brief      A type defined over the Matrix structure
*/
typedef struct dictionaryEntry DictionaryEntry;

/*
***************************** Statics *************************
*/

/**
 * @brief      The main words dictionary
 */
static const DictionaryEntry dictionary[]=
{
	{"le",ARTICLE},
	{"la",ARTICLE},
	{"chat",NOUN},
	{"souris",NOUN},
	{"mange",VERB},
	{"dort",VERB},
	{"joue",VERB},
	{"est",VERB},
	{"petite",ADJECTIVE},
	{"petit",ADJECTIVE},
	{"joli",ADJECTIVE},
	{"grosse",ADJECTIVE},
	{"bleu",ADJECTIVE},
	{"blanc",ADJECTIVE},
	{"verte",ADJECTIVE},
	{"Julie",PROPER_NOUN},
	{"Jean",PROPER_NOUN},
	{"Martin",PROPER_NOUN},
	{".",PERIOD}
};

/**
 * @brief      The transition matrix
 */
static InputState** transitionMatrix;

/**
 * @brief	Generates the transition matrix with the correct values
 */
void generateTransitionMatrix();

/**
 * @brief	Free the transition matrix
 */
void freeTransitionMatrix();

/**
 * Finds the type of a given word into the dictionary
 * @param  word The given word
 * @return      The type of the word
 */
InputType findTypeOfWord(char* word);

/**
 * Analyses the sentence and return wether it is correct or not
 * @param  sentence The given sentence to analyse
 * @return          1 if correct, 0 else
 */
int parseSentence(char* sentence);

/**
 * Determine which output type is to be return according to a given input state
 * @param  state The given input state
 * @return       The output type to be returned
 */
OutputState actionOfState(InputState state);

/**
 * Remove all the occurences of a char in the sentence
 * @param sentence     The sentence
 * @param charToRemove The char to remove
 */
void removeOccurences(char* sentence, char charToRemove);

#endif
