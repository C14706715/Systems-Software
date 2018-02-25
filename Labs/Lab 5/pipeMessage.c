/*
	Using the pipe and fork commands, 
	create a parent process that can send a message 
	to a child.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int fd[2], nbytes;
	pid_t pid;
	char string[] = "Hi friend!!\n";
	char readbuffer[100];
	
	//create the pipe 
	pipe(fd);
	
	//create the child process
	pid = fork();
	
	//this is the child
	if(pid == 0){
		//Take no input, close fd[0]
		close(fd[0]);
		
		//send output to parent via write
		write(fd[1], string, (strlen(string)+1));
		exit(0);
	}
	//this is the parent 
	else{
		//SEND NO OUTPUT, CLOSE FD[1]
		close(fd[1]);
		
		//Get input from the pipe via read
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Message from child: %s", readbuffer);
	}
}
	
	
