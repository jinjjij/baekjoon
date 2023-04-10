/*
https://www.acmicpc.net/problem/14215
*/

#include <stdio.h>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort3(int* a, int* b, int* c){
    if(*b<*c)     swap(b, c);
    if(*a<*b)     swap(a, b);
    if(*b<*c)     swap(b, c);
}


int main(void){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    sort3(&a, &b, &c);
    int ret = b+c;
    if(a<b+c){
        ret += a;
    }else{
        ret = ret*2 - 1;
    }

    printf("%d", ret);
    return 0;
}