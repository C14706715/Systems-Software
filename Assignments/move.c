#include <stdio.h>
#include <stdlib.h> // For exit()
 
int main()
{
    FILE *fptr1, *fptr2;
    char filename1[300], filename2[300], c;
    
    strcpy(filename1, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Offline/Offline.c");
    
    strcpy(filename2, "/Users/Jake/Library/Mobile\ Documents/com\~apple\~CloudDocs/DT282/Year\ 4/Modules/Semester\ 2/Systems\ Software/Assignments/Live/LiveFile.c");

 
   
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