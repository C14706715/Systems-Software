//A C program to demonstrate Zombie process.
//Child becomes Zombie as parent is sleeping
//When child process exits.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    //Fork returns process ID in parent process
    pid_t child_pid = fork();
    
    //Parent Process
    if(child_pid > 0){
        sleep(5);
    }
    else{
        //Child Process
        exit(1);
    }
    return 0;
}