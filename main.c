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

int main()
{
	generateTransitionMatrix();
	char testString[1000] = "le joli chat joue.";
	int test = parseSentence(testString);
	freeTransitionMatrix();
	return 0;
}
