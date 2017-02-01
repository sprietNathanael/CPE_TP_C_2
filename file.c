/**
 * CPE-TP2 : Automates de programmation
 *
 * @file	file.c
 * @brief   Tools to manage dictionary files
 * @author  Nathanaël SPRIET
 * @date	01/02/2017
 */

#include "file.h"

Dictionary* readDictionary(char* path)
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
		return(NULL);
	}
	int linesNumber = 0;
	// Browse line by line to get the number of lines
	while(getline(&currentLine, &length, filePointer) != -1)
	{
		linesNumber++;
	}
	// Memory allocation for the dictionary
	DictionaryEntry* customArray = malloc(linesNumber*sizeof(DictionaryEntry*));

	// Go back to the begining of file
	rewind(filePointer);
	char *foundWord;
	int i = 0;
	// Browse again line by line and put it in the dictionary
	while(getline(&currentLine, &length, filePointer) != -1)
	{
		// Find the first word
		foundWord = strtok(currentLine, " ");
		// Copy it to the dictionary
		strcpy(customArray[i].word,foundWord);
		// Find the type
		foundWord = strtok(NULL, " ");
		// Deduce the type from the string then save it to the dictionary
		customArray[i].inputType = charToInputType(foundWord[0]);
		printf("%s : %s ; %d\n", currentLine, customArray[i].word, customArray[i].inputType);
		i++;
	}
	// Create the new dictionary
	Dictionary* customDictionary = malloc(sizeof(Dictionary));
	customDictionary->array=customArray;
	customDictionary->size = linesNumber;

	// Close the file
	fclose(filePointer);
	return(customDictionary);
}
