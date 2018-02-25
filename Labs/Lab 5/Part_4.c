/*
	Using the pipe and fork commands, 
	create a program that uses the pipe command for: 
		ls -al|awk '{ print $3 }'|sort -u
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	int status;
	char readbuffer[1024];
	char string[] = "Message\n";

	fp = popen("ls -al", "awk'{print $3}'");

	while(fgets(readbuffer, 1024, fp) != NULL)
	{
		printf("%s", readbuffer);
	}

	status = pclose(fp);
}
