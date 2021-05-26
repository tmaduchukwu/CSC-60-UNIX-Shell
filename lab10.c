/* Author(s): Ruthann Biel                      	
 * This is csc60mshell.c
 * This is lab10.c the csc60mshell
 * This program serves as the base for doing labs 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in the directions.
 * Date: Spring 2021
 */
//Tobechi Maduchukwu
#include "lab9_10.h"


/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char cmdline[MAXLINE];
    char *argv[MAXARGS];
    int argc;

    // Loop forever to wait and process commands 
    while (TRUE) 
    {
	printf("\ncsc60msh> ");

	/* read the command the user types in */
	fgets(cmdline, MAXLINE, stdin);
	
	argc = ParseLine(cmdline, argv);
	/* Call ParseLine to build argc/argv; their limits declared above */
        // You write this call
   
    
	// REQUIRED: Just-to-make-sure printfs 
        printf("Argc = %i \n",  argc);
	int i;
	for(i = 0; i < argc; i++)
	{
            printf ("Argv %i = %s \n", i, argv[i]);
	}
	
	if (argc == 0) {
	   continue;
	}
	// If user hits enter key without a command, continue to loop again at the beginning 
	// You write this line.  Hint: if argc is zero, no command declared */


	if (strcmp(argv[0], "exit") == 0) {
	   exit(0);  
	}
	else if (strcmp(argv[0], "pwd") == 0) {
	   char arr[MAX_PATH_LENGTH];
	   getcwd(arr, MAX_PATH_LENGTH);
	   int p;
	   printf("%s", arr);
           continue;
	}
	else if (strcmp(argv[0], "cd") == 0) {
           char *dir;
	   if (argc == 1) {
	      dir = getenv("HOME");
	   }
 	   else {
	      dir = argv[1];
	   }
	   int chk = chdir(dir);
           if (chk < 0) {
	      perror("Error changing directory\n");
	   }
	   continue;
        }
	// Handle build-in command: exit, pwd, or cd 
        // See the directions for the algorithms to do these 3 commands.
	
        
        
        
        
        /* Else, fork off a process */
        else
	{
            RunExternalCommand(argc, argv);
			
	}      /* end of the if-else-if */

    }	       /* end of the while loop */
}   	       /* end of main */


