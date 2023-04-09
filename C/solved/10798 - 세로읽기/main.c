/*
https://www.acmicpc.net/problem/10798
*/

#include <stdio.h>
#include <string.h>

int isValid(char c){
    if('A' <= c && c <= 'Z'){
        return 1;
    }
    if('a' <= c && c <= 'z'){
        return 1;
    }
    if('0' <= c && c <= '9'){
        return 1;
    }

    return 0;
}


int main(void){
    char arr[5][20] = {0,};

    for(int i=0;i<5;i++){
        gets(arr[i]);
        /*
        for(int l=0;l<20;l++){
            printf("%d ", arr[i][l]);
        }printf("\n");
        */
    }

    int idx = 0;
    while(idx<16){
        for(int i=0;i<5;i++){
            char tmp = arr[i][idx];
            if(isValid(tmp)){
                printf("%c",tmp);
            }
        }
        idx++;
    }
    return 0;
}