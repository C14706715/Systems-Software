/*
    C Program to block write access
    of offline website
    
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
    openlog ("Permission Daemon", LOG_PID, LOG_DAEMON);
}

int main()
{
    int Eleven_Hour, Fifty_Minutes, Zero_Hour, Ten_Minutes;
    
    Eleven_Hour = 15;
    Fifty_Minutes = 02;
    Zero_Hour = 00;
    Ten_Minutes = 10;
    
    char Write_Mode[] = "0777";
    char Read_Mode[] = "000";
    char buf[300] = "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Offline/var/www/html.txt";
    int i;
    skeletonDaemon();

    while (1)
    {
        //TODO: Insert daemon code here.
        syslog (LOG_NOTICE, "Permission daemon started->Read Only");
        
            time(&now);
            right_now=localtime(&now);

            if(Eleven_Hour == right_now->tm_hour & Fifty_Minutes == right_now->tm_min){
                printf("Folder Changed to Read Only Access");
                
                FILE *fp;
                fp = fopen("/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/LogFile.txt","a");

                time_t now;
                time(&now);/* get current time; same as: now = time(NULL)  */ 

                char *buf2;
                buf2=(char *)malloc(10*sizeof(char));
                buf2=getlogin(); // get user logged in
                printf("\n %s \n",buf);

                if(fp == NULL) {
                    printf("Error opening file");
                    exit(1);
                }

                fprintf(fp,"\nModification\n\n");
                fprintf(fp,"Time    : %s\n", ctime(&now));
                fprintf(fp,"Status  : %s\n", "Successful - Read Only");
                fprintf(fp,"User    : %s\n\n\n",buf2);
                fclose(fp);
                
                i = strtol(Read_Mode, 0, 8);
                if (chmod (buf2, i) < 0)
                {
                    exit(1);
                }
                break;
            }
            else if(Zero_Hour == right_now->tm_hour & Ten_Minutes == right_now->tm_min){
                printf("Folder Changed to Write access");
                
                FILE *fp;
                fp = fopen("/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/LogFile.txt","a");

                time_t now;
                time(&now);/* get current time; same as: now = time(NULL)  */ 

                char *buf2;
                buf2=(char *)malloc(10*sizeof(char));
                buf2=getlogin(); // get user logged in
                printf("\n %s \n",buf);

                if(fp == NULL) {
                    printf("Error opening file");
                    exit(1);
                }

                fprintf(fp,"\nModification");
                fprintf(fp,"Time    : %s\n",ctime(&now));
                fprintf(fp,"Status  : %s\n", "Successful - Write Only");
                fprintf(fp,"User    : %s\n",buf2);
                fclose(fp);
                
                
                i = strtol(Write_Mode, 0, 8);
                if (chmod (buf,i) < 0)
                {
                    exit(1);
                }
                break;
            }
        
        sleep (20);
       
    }
    
    
    

    syslog (LOG_NOTICE, "Permission daemon terminated.");
    closelog();

    return EXIT_SUCCESS;
}
