/*
https://www.acmicpc.net/problem/10988
*/

#include <stdio.h>
#include <string.h>


int main(void){
    char word[110];
    scanf("%s", word);
    
    char temp[110];
    int size = strlen(word);

    for(int i=0;i<size;i++){
        temp[i] = word[size-1-i];
    }
    temp[size] = 0;

    int result = 0;
    if(!strcmp(word,temp)){
        result = 1;
    }

    printf("%d", result);


    return 0;
}