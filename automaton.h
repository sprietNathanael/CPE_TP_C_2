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

#define STATE_NUMBER 10
#define INPUT_STATE_NUMBER 7
#define WORD_MAX_SIZE 255

#define DICTIONARY_SIZE 18

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
typedef enum inputState InputState;

enum outputState
{
	NOT_FINISHED=-1,
	FAILURE=0,
	SUCCESS=1
};
typedef enum outputState OutputState;

enum inputType
{
	UNKNOWN_WORD=-1,
	ARTICLE=0,
	ADJECTIVE=1,
	NOUN=2,
	VERB=3,
	PROPER_NOUN=4,
	PERIOD=5
};
typedef enum inputType InputType;

struct dictionaryEntry
{
	char word[WORD_MAX_SIZE];
	InputType inputType;
};
typedef struct dictionaryEntry DictionaryEntry;

static const DictionaryEntry dictionary[]=
{
	{"le",ARTICLE},
	{"la",ARTICLE},
	{"chat",NOUN},
	{"souris",NOUN},
	{"mange",VERB},
	{"dort",VERB},
	{"joue",VERB},
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

static InputState** transitionMatrix;

void generateTransitionMatrix();

void freeTransitionMatrix();

InputType findTypeOfWord(char* word);

int parseSentence(char* sentence);

OutputState actionOfState(InputState state);

#endif
