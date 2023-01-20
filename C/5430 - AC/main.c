/*
https://www.acmicpc.net/problem/5430
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ac{
    int* arr;
    int front;
    int back;
    int size;
    int cap;
}AC;


AC* createAC(int cap){
    AC* newAC = (AC*)malloc(sizeof(AC));
    newAC->arr = (int*)malloc(sizeof(int) * cap);
    newAC->front = 0;
    newAC->back = 0;
    newAC->cap = cap;
    newAC->size = 0;

    return newAC;
}


void initAC(AC* ac){
    for(int i=0;i<ac->cap;i++){
        scanf("%d", &ac->arr[i]);
        ac->size ++;
        ac->back ++;
    }
    printf("initEnd\n");
}


void displayAC(AC* ac){
    printf("AC : [");
    for(int i=ac->front;i<ac->back;i++){
        printf("%d,", ac->arr[i]);
    }
    if(ac->size>0)  printf("%d]\n", ac->arr[ac->back]);
}


int main(void){
    int T;
    for(int t=0;t<T;t++){
        char func[100010];
        scanf("%s%*s", func);
        int funcSize = strlen(func);

        int N = 0;
        scanf("%*c%d", &N);
        printf("N : %d\n", N);
        AC* ac = createAC(N);
        initAC(ac);
        
        displayAC(ac);




        free(ac->arr);
        free(ac);
    }

    return 0;   
}