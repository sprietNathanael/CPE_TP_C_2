/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	file.c
 * @brief   Tools to manage dictionary files
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include "file.h"

int readDictionary(char* path)
{
	FILE* filePointer;
	char* currentLine = NULL;
	size_t length = 0;
	ssize_t read;
	// Try to open the file
	filePointer = fopen(path, "r");
	// If the file does not exists, return an error status
	if(filePointer == NULL)
	{
		return(-1);
	}
	// Browse line by line
	while(getline(&currentLine, &length, filePointer) != -1)
	{
		printf("Line : %s\n",currentLine);
	}

	fclose(filePointer);
	return(1);
}
