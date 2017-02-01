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
	int linesNumber = 0;
	// Browse line by line to get the number of lines
	while(getline(&currentLine, &length, filePointer) != -1)
	{
		linesNumber++;
	}
	// Memory allocation for the dictionary
	DictionaryEntry* customDictionary = malloc(linesNumber*sizeof(DictionaryEntry*));

	// Go back to the begining of file
	rewind(filePointer);
	char *foundWord;
	int i = 0;
	// Browse again line by line and put it in the dictionary
	while(getline(&currentLine, &length, filePointer) != -1)
	{
		// Found the first word
		foundWord = strtok(currentLine, " ");
		strcpy(customDictionary[i].word,foundWord);
		foundWord = strtok(NULL, " ");
		customDictionary[i].inputType = charToInputType(foundWord[0]);
		printf("%s : %s ; %d\n", currentLine, customDictionary[i].word, customDictionary[i].inputType);
		i++;

	}

	fclose(filePointer);
	return(1);
}
