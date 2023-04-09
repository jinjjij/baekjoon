/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>


// 0.25 , 0.1 , 0.05 , 0.01

int main(void){
    int T = 0;
    scanf("%d", &T);

    int money;
    int q,d,n,p;

    for(int t=0;t<T;t++){
        scanf("%d", &money);

        q = money/25;
        money %= 25;
        d = money/10;
        money %= 10;
        n = money/5;
        money %= 5;
        p = money;

        printf("%d %d %d %d\n", q, d, n, p);
    }
    return 0;
}