/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct largeInt{
    int size;
    char* num;
} LINT;


LINT* createLINT(int size){
    LINT* lint = (LINT*)malloc(sizeof(LINT));
    lint->size = size;
    lint->num = (char*)calloc(size, sizeof(char));

    return lint;
}


void destroyLINT(LINT* lint){
    free(lint->num);
    free(lint);
}


void printLINT(LINT* lint){
    for(int i=0;i<lint->size;i++){
        printf("%c",lint->num[lint->size-i-1]+'0');
    }
}



int max(int arg1, int arg2){
    return arg1>arg2?arg1:arg2;
}


// return value == carry
char addbit(char a, char b, char c, char* out){
    *out = (a+b+c)%10;
    return (a+b+c)/10;
}


void addLINT(LINT* out, LINT* arg1, LINT* arg2){
    char carry = 0;
    char out;
    char a,b;
    for(int i=0;i<max(arg1->size,arg2->size);i++){
        if(i>=arg1->size)    a = 0;
        if(i>=arg2->size)    b = 0;
        carry = addbit(a, b, carry, &out);

    }
}


char multiplybit(char a, char b, char carry, char* out){
    *out = (a*b+carry)%10;
    return (a*b+carry)/10;
}


void multiplyLINT(LINT* out, LINT* arg1, LINT* arg2){
    int maxSize = max(arg1->size, arg2->size);

}



int main(void){

    return 0;
}