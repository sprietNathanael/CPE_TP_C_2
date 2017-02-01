/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	file.h
 * @brief   Tools to manage dictionary files
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "automaton.h"

#ifndef FILE_H
#define FILE_H

/**
 * Read dictionary from a file
 * @param  path A path to the file
 * @return      The created dictionary
 */
Dictionary* readDictionary(char* path);

#endif
