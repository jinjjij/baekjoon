/*
https://www.acmicpc.net/problem/1022
*/

#include <stdio.h>


void pr(int x, int Num){
    switch(Num){
        case 1:
            printf("%1d",x);   break;
        case 2:
            printf("%2d",x);   break;
        case 3:
            printf("%3d",x);   break;
        case 4:
            printf("%4d",x);   break;
        case 5:
            printf("%5d",x);   break;
        case 6:
            printf("%6d",x);   break;
        case 7:
            printf("%7d",x);   break;
        case 8:
            printf("%8d",x);   break;
        case 9:
            printf("%9d",x);   break;
        case 10:
            printf("%10d",x);   break;
    }
}


int abs(int a){
    return a>0?a:-a;
}


int max(int a, int b){
    return a>b?a:b;
}


int getCorner(int Sabunmeon, int n){
    if(n == 0)  return 1;
    n--;
    int ret = 4*n*n + 6*n + 3;
    n++;
    switch (Sabunmeon)
    {
        case 2:
            ret += 2*n;
            break;
        case 3:
            ret += 4*n;
            break;
        case 4:
            ret -= 2*n;
            break;
        default:
            break;
    }

    return ret;
}


int num(int x, int y){
    int c = max(abs(x), abs(y));
    int ret = 0;

    if(y == -c){
        ret = getCorner(3, c);
        ret += c + x;
    }else if(x == -c){
        ret = getCorner(2, c);
        ret += c - y;
    }else if(y == c){
        ret = getCorner(1, c);
        ret += c - x;
    }else if(x == c){
        ret = getCorner(4, c);
        ret += c + y;
    }else{
        fprintf(stderr, "\ndirErr\n");
    }

    return ret;
}


int getDigit(int n){
    if(n>9){
        return getDigit(n/10) + 1;
    }else{
        return 1;
    }
}


void printInSquare(int x1, int y1, int x2, int y2){
    int m = num(x1, y1);
    m = max(m,num(x1,y2));
    m = max(m,num(x2,y1));
    m = max(m,num(x2,y2));

    int digit = getDigit(m);

    for(int y=y2;y>=y1;y--){
        for(int x=x1;x<x2;x++){
            pr(num(x,y), digit);
            printf(" ");
        }
        pr(num(x2, y), digit);
        printf("\n");
    }
}

int main(void){
    int x1,x2,y1,y2;
    scanf("%d %d %d %d", &y1,&x1,&y2,&x2);
    printInSquare(x1,-y2,x2,-y1);
    return 0;
}