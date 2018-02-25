#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(){
	int fd;
	char * fifoFile = "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Labs/Lab\ 5/Part_5";
	char buf[MAX_BUF];
	
	fd = open(fifoFile, O_RDONLY);
	read(fd, buf, MAX_BUF);
	printf("Message in: %s\n", buf);
	close(fd);
	
	return 0;
}
