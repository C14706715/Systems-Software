/*
    Create a C program that can compare two times and countdown to a specific time. (ie like an alarm clock!!).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t now;
struct tm *right_now;

int main(){
    int hour, minutes;
    
    printf("Enter Hour: ");
    scanf("%d", &hour);
    printf("Enter Minutes: ");
    scanf("%d", &minutes);
    
    system("clear");
    
    while(1){
        time(&now);
        right_now=localtime(&now);
        
        if(hour == right_now->tm_hour & minutes == right_now->tm_min){
            printf("\n!!! Wake up !!!");
            printf("\a");
            break;
        }
    }
    return 1;
}