/************************************
* Developer: Ovi         		    *
* Version:    1.0                   *    
* Description: API for stack.c      * 
*************************************/
#include <string.h> /* For strcpy */
#include <stdio.h> /* For printf */
#include <stdlib.h> /* For malloc and free */
#include "ws5_ex2_engine.h"/* For header files */

int CheckInput (const char *input, const char *command) /* Checks user input against list of known commands */
{
	return strcmp(input, command) ;
}

int CheckInputAppend (const char *input, const char *command) /* Checks user input against list of known commands */
{
	UNUSED(command);
	if( input[0] == '<' )
	{
		return 0;
	}
	
	return 1;
}
int ActionRemove (char *chosen_file, char *input) /* Removes file if found */
{
	printf("%s\n", chosen_file);
	UNUSED(input);
	if (remove(chosen_file) == 0)
	{
    	printf("Deleted successfully\n");
	}
    else
    {
      printf("Unable to delete the file\n");
    }
  
   return 0;
}

int ActionCount (char *chosen_file, char *input) /* counts number of lines in file */
{
    size_t count = 0;
    char c; 
	FILE *fp = fopen(chosen_file, "r");
	
	UNUSED(input);
	if (NULL == fp) 
	{
    	printf("Error opening file %s\n", chosen_file);
    	return -1;
	}
    
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n') 
        {
        	++count;
        }
    }
 
    fclose(fp);
    
    printf("The chosen file has %lu lines\n ", count);
 
	return 0;
}

int ActionExit (char *chosen_file, char *input) /* closes program Need to add free */
{
	UNUSED(chosen_file);
	UNUSED(input);
	exit(1);
}

int ActionAppend (char *chosen_file, char *input) /* appends text to specified file */
{
	char append[300] = {0};
	++input;
	
	if (NULL == chosen_file) 
	{
    	printf("Error opening file.");
    	return -1;
	}
	

	sprintf(append, "sed -i '1s/^/%s\\n/' %s",input,chosen_file);
	system(append);
	
	return 0;	
}	
