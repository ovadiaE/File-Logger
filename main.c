#include <stdio.h> /* Input Output */
#include <stdlib.h> /* NULL  */
#include <string.h> /* string functions */

#include "ws5_ex2_engine.h" /* header file */
#define number_of_commands 4

typedef struct ACTION 
{
  char *command;
  int (*CompareInput) (const char *, const char *);
  int (*ActionFunc) (char *chosen_file, char *input);
  
} ACTIONS;


int main (int argc, char *argv[]) 
{	

	if( argc == 2)
		StartLogger(argv[1]);
	
	return 0;
}

int InitStructArray (ACTIONS action_array[]) /* Initializes data structure for use in StartLogger*/
{	
	char *command_list[4] = {"-remove", "-count", "-exit", "<"};
	int (*function_array[4]) () = {ActionRemove, ActionCount, ActionExit, ActionAppend};
	char *command_name = NULL;
	
	size_t i = 0;
	
	for (i = 0; i < number_of_commands; ++i) 
	{
		ACTIONS action;
				
		command_name = (char*)malloc(sizeof(char) * strlen(command_list[i]));		
		if(NULL == command_name)
		{
			printf("Memory allocation failed in function: InitializeStruct\n");
			free(command_name);
			return -1;
		}
	
		action.command = command_name;
		strcpy(action.command, command_list[i]); /* appends current command at index i to struct */	
					
		action.CompareInput = CheckInput;  /* appends check input function to struct */
		
		if( i == 3)
			action.CompareInput = CheckInputAppend;
			
		action.ActionFunc = function_array[i];
		
		action_array[i] = action;
	}	
	
	return 0;	
}

int StartLogger(char *file_name) /* runs loop on struct array executes commands based on user input */
{
	size_t i = 0;
	char input[200];
	char *chosen_file = file_name;
	
	ACTIONS action_array[number_of_commands];
	InitStructArray (action_array);
	
	while(1)
	{
		scanf("%[^\n]%*c", input);
		
		for(i = 0; i < number_of_commands; ++i) /* Loop runs number of possible commands */
		{
			ACTIONS current_struct = action_array[i]; /* Renamed arr[i] to current_struct */
			 if (0 == current_struct.CompareInput (input, action_array[i].command))
			 {
				current_struct.ActionFunc(chosen_file, input);	
				break;
			}
		}

	}
	return 0;
}

