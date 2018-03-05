#include <stdio.h>
#include <stdlib.h> // For exit()
 
int main()
{
    FILE *fptr1, *fptr2;
    char OfflineFile[300], LiveFile[300], c;
    
    strcpy(OfflineFile, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Offline/Offline.c");
    
    strcpy(LiveFile, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Live/LiveFile.c");

 
   
    // Open one file for reading
    fptr1 = fopen(OfflineFile, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", OfflineFile);
        exit(0);
    }
 
    // Open another file for writing
    fptr2 = fopen(LiveFile, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", LiveFile);
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
 
    printf("\nContents copied to %s", LiveFile);
 
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}