/*
https://www.acmicpc.net/problem/11758
*/

#include <stdio.h>
#include <math.h>



int main(void){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    int v1_x,v1_y,v2_x,v2_y;
    v1_x = x2 - x1;
    v1_y = y2 - y1;
    v2_x = x3 - x2;
    v2_y = y3 - y2;

    int a = (x2 - x1)*(y3 - y2) - (y2 - y1)*(x3 - x2);
    if(a>0){
        printf("1");
    }else if(a<0){
        printf("-1");
    }else{
        printf("0");
    }
    return 0;
}