#include <stdio.h>
#include <stdlib.h>



/*  dir
    1 : clockwise
    0 : anti clockwise
*/
double polygonArea(double* X, double* Y, int size){
    double area = 0;
    int j = size - 1;

    for(int i=0;i<size;i++){
        area += (X[j]+X[i]) * (Y[j]-Y[i]) / 2;
        j = i;
    }

    if(area<0)
        area = -area;
    return area;
}


int main(void){
    int N;
    scanf("%d",&N);
    double* x = (double*)malloc(sizeof(double) * N);
    double* y = (double*)malloc(sizeof(double) * N);

    for(int i=0;i<N;i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("%.1lf",polygonArea(x,y,N));
    free(x);
    free(y);
    return 0;
}