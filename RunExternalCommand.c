//  function RunExternalCommand

#include "lab9_10.h"

void RunExternalCommand(int argc, char **argv)
{
    int status;
    pid_t pid;
    
    pid = fork();
	
    switch(pid)
    {
	case -1:
            perror("Error on the call of fork\n");
	    exit(EXIT_FAILURE);
	case 0:
	    /* I am child process. 
	       I will execute the command, call: execvp */
	    ProcessInput(argc, argv);
	    break;
	default:
	    /* I am parent process */
	    if (wait(&status) == -1)
	        perror("Parent Process - Error on fork/switch\n");
	    else
		printf("Child returned status: %d\n\n",status);
		break;
    }  /* end of the switch */
	
    return;
}
