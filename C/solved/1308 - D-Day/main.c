/*
https://www.acmicpc.net/problem/1308 - D-Day
*/

#include <stdio.h>
#include <stdlib.h>


int monthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


int is1000Year(int y1, int m1, int d1, int y2, int m2, int d2){

    if(y2-y1>1000){
        return 1;
    }else if(y2-y1 == 1000){
        if(m2>m1){
            return 1;
        }else if(m2 == m1){
            if(d2 >= d1){
                return 1;
            }
        }
    }

    return 0;
}


int isYoon(int y){
    int ret = 0;
    if(y%400==0){
        ret = 1;
    }else if(y%100==0){
        ret = 0;
    }else if(y%4 == 0){
        ret = 1;
    }

    return ret;
}


int toDay(int y, int m, int d){
    int ret = d;
    int yoon = 0;
    for(int i=1;i<y;i++){
        yoon = isYoon(i);

        ret += 365 + yoon;
    }

    for(int i=1;i<m;i++){
        ret += monthDay[i];
        if(i == 2 && isYoon(y)){
            ret += 1;
        }
    }


    return ret;
}


int main(void){
    int y,m,d,y1,m1,d1;
    scanf("%d %d %d",&y,&m,&d);
    int curDay = toDay(y,m,d);
    scanf("%d %d %d",&y1,&m1,&d1);
    int Dday = toDay(y1,m1,d1);
    if(is1000Year(y,m,d,y1,m1,d1)){
        printf("gg");
    }else{
        printf("D-%d",Dday-curDay);
    }
    
    return 0;
}