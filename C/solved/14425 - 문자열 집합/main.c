/*
https://www.acmicpc.net/problem/14425 - 문자열 집합

230106 - 230107
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int cmp(const void* arg1, const void* arg2){
    char** str1 = (char**)arg1;
    char** str2 = (char**)arg2;

    return strcmp(*str1, *str2);
}


int main(void){
    int N = 0;
    int M = 0;
    
    scanf("%d %d ", &N, &M);

    char** chrArr = malloc(sizeof(char*) * N);

    char buff[510];
    for(int n=0;n<N;n++){
        scanf(" %s", buff);
        char* chrBuf = strdup(buff);
        chrArr[n] = chrBuf;
    }


    qsort(chrArr, N, sizeof(char*), cmp);


    int checksum = 0;
    for(int m=0;m<M;m++){
        scanf("%s", buff);
        char* chrBuf = strdup(buff);
        if(bsearch(&chrBuf, chrArr, N, sizeof(char*), cmp) != NULL){
            checksum ++;
        }
    }

    free(chrArr);
    printf("%d", checksum);
    return 0;
}
