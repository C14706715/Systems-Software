/*
    Create a program that manages the process of automatically creating a log file in a directory. This should be a separate process. If this process terminates unexpectedly the main program should be informed via an appropriate signal
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char string[] = "Jake's Output Log file";

	pid_t pid = fork();

	if(pid == 0){
		FILE *fptr;
		fptr = fopen("log.txt", "w");

		if(fptr == NULL){
			printf("Error!");
			exit(1);
		}

		// Write the string to the file
		fprintf(fptr, "%s", string);

		// Close the file
		fclose(fptr);

		return 0;
	}

	return 0;
}