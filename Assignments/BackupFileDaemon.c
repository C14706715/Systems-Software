/*
    Create a daemon update the contents of the live website folder every night at 11:59
    
    Jake Young 
    C14706715
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
    int Eleven_Hour, FiftyNine_Minutes;
    
    Eleven_Hour = 23;
    FiftyNine_Minutes = 59;
    
    FILE *fptr1, *fptr2;
    char filename1[300], filename2[300], c;
    
    strcpy(filename1, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Offline/var/www/html.txt");
    
    strcpy(filename2, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Live/var/www/html.txt");

    skeletonDaemon();

    while (1)
    {
        //TODO: Insert daemon code here.
        syslog (LOG_NOTICE, "Backup File Daemon Started");
        
        time(&now);
        right_now=localtime(&now);

        if(Eleven_Hour == right_now->tm_hour & FiftyNine_Minutes == right_now->tm_min){
            // Open one file for reading
            fptr1 = fopen(filename1, "r");
            if (fptr1 == NULL)
            {
                printf("Cannot open file %s \n", filename1);
                exit(0);
            }
 
            // Open another file for writing
            fptr2 = fopen(filename2, "w");
            if (fptr2 == NULL)
            {
                printf("Cannot open file %s \n", filename2);
                exit(0);
            }

            // Read contents from file
            c = fgetc(fptr1);
            while (c != EOF)
            {
                fputc(c, fptr2);
                c = fgetc(fptr1);
            }

            printf("\nContents copied to %s", filename2);

            fclose(fptr1);
            fclose(fptr2);
            return 0;
        }
        sleep (20);
    }

    syslog (LOG_NOTICE, "Backup File Daemon Terminated.");
    closelog();

    return EXIT_SUCCESS;
}