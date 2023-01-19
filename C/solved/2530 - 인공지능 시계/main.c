/*
https://www.acmicpc.net/problem/2530 - 인공지능 시계
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct time{
    int hour;       // 0 - 23
    int min;        // 0 - 59
    int sec;        // 0 - 59
} TIME;


TIME* createTime(int hour, int min, int sec){
    TIME* time = (TIME*)malloc(sizeof(TIME));
    time->hour = hour;
    time->min = min;
    time->sec = sec;
    return time;
}


void destroyTime(TIME* time){
    free(time);
}


void addTime(TIME* time, TIME* addTime){
    int s = time->sec + addTime->sec;
    int m = time->min + addTime->min;
    int h = time->hour + addTime->hour;

    m += s/60;
    s %= 60;
    h += m/60;
    m %= 60;
    h %= 24;

    time->hour = h;
    time->min = m;
    time->sec = s;
}


void printTime(TIME* time){
    printf("%d %d %d", time->hour, time->min, time->sec);
}


int main(void){
    int h,m,s,adds;
    scanf("%d %d %d", &h, &m, &s);
    scanf("%d", &adds);
    TIME* a = createTime(h,m,s);
    TIME* b = createTime(0,0,adds);
    addTime(a,b);
    printTime(a);
    destroyTime(a);
    destroyTime(b);
    return 0;
}