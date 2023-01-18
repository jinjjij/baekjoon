/*
https://www.acmicpc.net/problem/1264 - 모음의 개수
*/

#include <stdio.h>


int isMo(char c){
    int ret = 0;
    switch(c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            ret = 1;
            break;

        default:
            ret = 0;
    }

    return ret;
}


int main(void){
    int sum = 0;
    while(1){
        char c = getchar();
        sum += isMo(c);

        if(c == '\n'){
            printf("%d\n", sum);
            sum = 0;
        }

        if(c == '#')    break;
    }
    return 0;
}