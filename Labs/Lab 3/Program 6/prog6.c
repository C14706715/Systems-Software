/*
    Create a program to change the permissions of the log file to 777
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	char mode[] = "0777";
	char buff[250] = "log.txt";
	int i = 0;

	i = strtol(mode, 0, 8);

	if(chmod(buff, i) < 0){
		fprintf(stderr, "%s: error in chmod(%s, %s) - %d (%s)\n", argv[0], buff, mode, errno, strerror(errno));
        exit(1);
	}

	return(0);
}