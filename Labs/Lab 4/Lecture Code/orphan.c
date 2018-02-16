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
    return 0;
}