/*
    Create a program to display all the names stored in the log file from part 4 above
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	int c;

	if(pid == 0){
		FILE *fptr;

		fptr = fopen("log.txt", "r");

		if(fptr == NULL){
			printf("Error!");
			exit(1);
		}

		while((c = getc(fptr)) != EOF){
			putchar(c);            
		}
        printf("\n");

		// Close the file
		fclose(fptr);
		return 0;
	}
	return 0;
}