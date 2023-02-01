/*
https://www.acmicpc.net/problem/10775
*/

#include <stdio.h>


int main(void){
    int G,P;
    int gates[100001] = {0,};
    int nextPos[100001] = {0,};
    int count = 0;
    int flg = 0;

    scanf("%d", &G);
    scanf("%d", &P);
    for(int i=0;i<P;i++){
        int gi = 0;
        scanf("%d", &gi);

        if(flg) break;

        int index = gi-1;

        while(index >= 0 && gates[index]!=0){
            index--;
        }
        

        if(index<0) flg=1;
    }

    printf("%d", count);
    return 0;   
}