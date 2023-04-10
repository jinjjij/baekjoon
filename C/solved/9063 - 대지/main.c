/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>

int main(void){
    int xMin = 100000;
    int yMin = 100000;
    int xMax = -100000;
    int yMax = -100000;

    int N = 0;
    scanf("%d", &N);

    int x,y;
    for(int i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        if(x < xMin){
            xMin = x;
        }
        if(x > xMax){
            xMax = x;
        }
        if(y < yMin){
            yMin = y;
        }
        if(y > yMax){
            yMax = y;
        }
    }

    printf("%d", (xMax-xMin)*(yMax-yMin));
    return 0;
}