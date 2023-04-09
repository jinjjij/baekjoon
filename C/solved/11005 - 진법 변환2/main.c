/*
https://www.acmicpc.net/problem/11005
*/

#include <stdio.h>


char itoc(int i){
    if(0<=i && i<= 9){
        return (char)(i+'0');
    }

    if(10 <= i && i <= 35){
        return (char)(i-10 +'A');
    }
}


int main(void){
    int N, B;
    scanf("%d %d", &N, &B);

    char output[100] = {0,};
    int len = 0;

    while(N>=B){
        output[len++] = itoc(N%B);
        N/=B;
    }
    output[len++] = itoc(N);
    
    for(int i=0;i<len;i++){
        printf("%c", output[len-i-1]);
    }

    return 0;
}