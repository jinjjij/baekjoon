/*
https://www.acmicpc.net/problem/10101
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


void func(int a, int b, int c){
    
    sort3(&a, &b, &c);

    if(a>=b+c){
        printf("Invalid");
    }
    else if(a==b && b==c){
        printf("Equilateral");
    }
    else if(a==b || b==c || c==a){
        printf("Isosceles");
    }
    else{
        printf("Scalene");
    }
    printf("\n");
}


int main(void){
    int a,b,c;

    while(1){
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        if(a==0 && b==0 && c==0){
            break;
        }else{
            func(a,b,c);
        }
    }
    
    return 0;
}