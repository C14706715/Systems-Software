/*
	Create two processes that are not related that 
	can communicate with each other. 
	(Hint use FIFO Named Pipe)
*/
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;
	char *fifoFile = "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Labs/Lab\ 5/Part_5";

	// Create FIFO 
	mkfifo(fifoFile, 0666);

	fd = open(fifoFile, O_WRONLY);
	write(fd, "The truth is out there!", sizeof("The truth is out there!"));
	close(fd);

	unlink(fifoFile);

	return 0;
}