/* ----------------------------------------------------------------- */
/*                  process_input                                    */
/* ----------------------------------------------------------------- */

#include "lab9_10.h"

void ProcessInput(int argc, char **argv) 
{                      

    /* Step 1: Call Redirection to deal with operators:            */
    /* < , or  >, or both                                           */
	Redirection(argc, argv);
	int ret = execvp(argv[0], argv);	    

    /* Step 2: perform system call execvp to execute command        */
    /* Hint: Please be sure to review execvp.c sample program       */
	if (ret == -1) {                                        
        	fprintf(stderr, "Error on the exec call\n");              
        	_exit(EXIT_FAILURE);                                      
     	}                                                            
 
 }
/* ----------------------------------------------------------------- */
