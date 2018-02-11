/*
    Create a program to ask a user for their name and then append this to a log file (text file)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char string[] = "Jake's Output";
	char name[50];
	printf("Enter your First Name: ");
	scanf("%s", name);

	pid_t pid = fork();

	if(pid == 0)
	{
		FILE *fptr;

		fptr = fopen("log.txt", "a");

		if(fptr == NULL)
		{
			printf("Error!");
			exit(1);
		}

		// Write the string to the file
		fprintf(fptr, "\n%s", name);

		// Close the file
		fclose(fptr);

		return 0;
	}

	else
	{
		// Parent continues
	}

	return 0;
}