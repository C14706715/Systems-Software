/*
    C Program to track the changes of the multiple users file in the offline directory
    
    Jake Young 
    C14706715
*/

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{
    struct stat info;
    struct stat s = {0};
    char sentence[1000];
    FILE *fptr;

    stat("/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Offline/var/www/html.txt", &info);

    fptr = fopen("/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/ModificationHistory.txt", "a");
    
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    
    fprintf(fptr,"\nLast Modified: %.12s\nUser ID: %u\n\n",4+ctime(&info.st_mtimespec), s.st_uid);
    printf("\nLast Modified %.12s\nUser ID: %u\n\n", 4+ctime(&info.st_mtimespec), s.st_uid);
    
    fclose(fptr);
    return 0;
}