/*
https://www.acmicpc.net/problem/4999
*/

#include <stdio.h>
#include <string.h>


int main(void){
    char buffer[1010];
    scanf("%s",buffer);
    int me = strlen(buffer);
    scanf("%s",buffer);
    int docter = strlen(buffer);
    if(me<docter){
        printf("no");
    }else{
        printf("go");
    }
    return 0;
}