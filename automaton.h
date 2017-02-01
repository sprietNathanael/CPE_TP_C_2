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
	{"chat",NOUN},
	{"souris",NOUN},
	{"mange",VERB},
	{"la",ARTICLE},
	{"petite",ADJECTIVE},
	{".",PERIOD},
	{"bleu",ADJECTIVE},
	{"dort",VERB},
	{"julie",PROPER_NOUN}
};

InputState** generateTransitionMatrix();

void freeTransitionMatrix(InputState** transitionMatrix);
InputType findTypeOfWord(char* word);

int parseSentence(char* sentence);

#endif
