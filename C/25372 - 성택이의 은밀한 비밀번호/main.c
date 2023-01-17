/*
https://www.acmicpc.net/problem/25372 - 성택이의 은밀한 비밀번호
*/

#include <stdio.h>
#include <string.h>


int main(void){
    int N, len;
    char buffer[30];
    scanf("%d", &N);
    

    for(int n=0;n<N;n++){
        scanf("%s", buffer);
        len = strlen(buffer);
        if(len < 6 || len > 9){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}