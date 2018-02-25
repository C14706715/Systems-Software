/*
	Using the popen command, 
	recreate the examples from Part 1 and 2.
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

	fp = popen("ls *", "r");

	while(fgets(readbuffer, 1024, fp) != NULL)
	{
		printf("%s", readbuffer);
	}

	status = pclose(fp);
}