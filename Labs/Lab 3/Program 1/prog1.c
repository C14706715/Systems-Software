/*
    Write a C program to emulate the ls -l UNIX command that prints all files in a current directory. Hint: Use the exec command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	execl("/bin/ls", "ls", "-l");
	return 0;
}