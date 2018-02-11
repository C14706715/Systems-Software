/*
    Write a C program to offer the following functionality:
    a. List all the processes running on a system if no params are
    passed via the command line
    b. Search for a process by name eg. ./myprog search
    calculator
    c. Kill a process for a given IPD rg. ./myprog kill 1292
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    execl("/bin/ls", "ps -A", "ps -A");
	return 0;
}