/*
    Create a daemon to change the permissions of a folder to 000 at a specific time every day, and to change the permissions to 777 at another time. Eg set to 777 at 9am and set to 000 at 5pm.
*/  


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
time_t now;
struct tm *right_now;

static void skeletonDaemon()
{
    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    /* Catch, ignore and handle signals */
    //TODO: Implement a working signal handler */
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* Set new file permissions */
    umask(0);

    /* Change the working directory to the root directory */
    /* or another appropriated directory */
    chdir("/");

    /* Close all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }

    /* Open the log file */
    openlog ("firstdaemon", LOG_PID, LOG_DAEMON);
}

int main()
{
    int Zero_Hour, Zero_Minutes, Seven_Hour, Seven_Minutes;
    
    Zero_Hour = 15;
    Zero_Minutes = 32;
    Seven_Minutes = 18;
    Seven_Minutes = 32;
    
    char seven_mode[] = "0777";
    char zero_mode[] = "0000";
    char buf[100] = "./SampleFile.c";
    int i;
    skeletonDaemon();

    while (1)
    {
        //TODO: Insert daemon code here.
        syslog (LOG_NOTICE, "First daemon started.");
        
            time(&now);
            right_now=localtime(&now);

            if(Zero_Hour == right_now->tm_hour & Zero_Minutes == right_now->tm_min){
                printf("File Changed to Zero");
                i = strtol(zero_mode, 0, 8);
                if (chmod (buf,i) < 0)
                {
                    exit(1);
                }
                break;
            }
            else if(Seven_Hour == right_now->tm_hour & Seven_Minutes == right_now->tm_min){
                printf("File Changed to Seven");
                i = strtol(seven_mode, 0, 8);
                if (chmod (buf,i) < 0)
                {
                    exit(1);
                }
                break;
            }
        
        sleep (20);
       
    }

    syslog (LOG_NOTICE, "First daemon terminated.");
    closelog();

    return EXIT_SUCCESS;
}
