/**************************
* Name:  Ovadia Esquenazi *          
* Ex:    engine.h         *
* ws:    5                *
**************************/

#define UNUSED(X) (void)(X)
int CheckInput(const char *input, const char *command);
int CheckInputAppend(const char *input, const char *command);
int ActionRemove(char *chosen_file, char *input);
int ActionCount(char *chosen_file, char *input);
int ActionExit(char *chosen_file, char *input);
int ActionAppend(char *chosen_file, char *input);
int ActionDefault (char *chosen_file, char *input);
int	StartLogger(char *file_name);
