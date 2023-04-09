/*
https://www.acmicpc.net/problem/2745
*/

#include <stdio.h>
#include <string.h>


int ctoi(char c){
    if('0' <= c && c <= '9'){
        return c-'0';
    }

    if('A' <= c && c <= 'Z'){
        return c-'A'+10;
    }
}


int main(void){
    char str[100];
    int B;

    scanf("%s %d", str, &B);
    int len = strlen(str);


    long int output = 0;
    for(int i=0;i<len;i++){
        output *= B;
        output += ctoi(str[i]);
    }

    
    printf("%ld", output);
    return 0;
}