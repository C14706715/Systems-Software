#include <stdio.h>
#include <stdlib.h>

int main(){
    //Create a child process
    int pid = fork();
    
    if(pid > 0){
        //if PID > 0 => this is the parent
        //this process performs printf and finishes
        printf("\nParent Process");
        //wait 10 seconds before process ends
        sleep(10);
        //Kill the parent
        exit(EXIT_SUCCESS);
    }
    else if(pid == 0){
        printf("Child Process");
        
        //Keep the process running in a infinite loop
        //When the parent finisheds after 10 seconds,
        //the getpid() will return 1 as the parent (init process)
        while(1){
            sleep(1);
            printf("\nChild 1: My parent is: %i\n", getpid());
        }
    }
    
    //Step 2 => Elevate the orphan process to session leader, to loose controlling of TTY
    //This command runs the process in a new session
    if(setsid() < 0){
        exit(EXIT_FAILURE);
    }
    
    //Step 3 => call umask() to set the file mode creation mask to 0
    //This will allow the daemon to read and write files
    //with the permissions/access required
    umask(0);
    
    //Step 4 => Change the current working dir to root
    //This will eliminate any issues of running on a mounterd drive,
    //that potentially could be removed etc..
    if(chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }
    
    //Step 5 => Close all open file descriptors
    for(x = sysconf(_SC_OPEN_MAX); x >= 0; x --){
        close(x);
    }
    return 0;
}