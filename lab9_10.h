// The header file for lab 9 & 10

/* The include files section */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* Define Section */
#define MAXLINE 80
#define MAXARGS 20
#define MAX_PATH_LENGTH 50
#define TRUE 1

/* function prototypes */
int ParseLine(char *cmdline, char **argv);
void ProcessInput(int argc, char **argv); 
void Redirection(int argc, char **argv); 
void RunExternalCommand(int argc, char **argv);
