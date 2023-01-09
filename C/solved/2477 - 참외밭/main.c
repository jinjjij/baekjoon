/*
https://www.acmicpc.net/problem/2477 - 참외밭



// 동쪽은 1, 서쪽은 2, 남쪽은 3, 북쪽은 4
*/

#include <stdio.h>
#include <stdlib.h>



/*  dir
    1 : clockwise
    0 : anti clockwise
*/
int polygonArea(int* X, int* Y, int size, int dir){
    int area = 0;
    int j = size - 1;

    for(int i=0;i<size;i++){
        area += (X[j]+X[i]) * (Y[j]-Y[i]) / 2;
        j = i;
    }

    if(!dir)
        area = -area;
    return area;
}



int main(void){
    int K = 0;
    int area = 0;

    int dir, dist, xCur, yCur;
    int CoordX[7];
    int CoordY[7];

    scanf("%d", &K);

    xCur = 0;
    yCur = 0;

    CoordX[0] = 0;
    CoordY[0] = 0;

    for(int i=1;i<7;i++){
        scanf("%d %d", &dir, &dist);
        switch(dir){
            case 1:
                xCur += dist;
                break;
            case 2:
                xCur -= dist;
                break;
            case 3:
                yCur -= dist;
                break;
            case 4:
                yCur += dist;
                break;
            default:
                printf("Error!\n");
        }

        CoordX[i] = xCur;
        CoordY[i] = yCur;
    }



    area = polygonArea(CoordX, CoordY, 7, 0);
    printf("%d", area * K);

    return 0;
}