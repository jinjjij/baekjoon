/*
https://www.acmicpc.net/problem/1106 - 호텔
*/

#include <stdio.h>



int A[1110];
int price[30];
int customer[30];
int C,N;


void init(void){
    for(int i=0;i<1110;i++){
        A[i] = -1;
    }
    A[0] = 0;
}


// return minimum price
int process(int cust){
    if(cust < 0)    return -1;
    if(A[cust]!=-1)  return A[cust];

    int min = -1;
    for(int i=0;i<N;i++){
        int temp = process(cust - customer[i]);
        if(temp == -1)  continue;

        temp += price[i];
        if(temp < min || min==-1){
            min = temp;
        }
    }
    A[cust] = min;
    //printf("A[%d] = %d\n",cust,min);
    return min;
}


int main(void){
    init();
    scanf("%d %d", &C, &N);
    
    int maxCust = 0;
    for(int i=0;i<N;i++){
        scanf("%d %d",&price[i],&customer[i]);
        if(customer[i] > maxCust){
            maxCust = customer[i];
        }
    }

    int min = -1;
    
    for(int i=0;i<maxCust;i++){
        int temp = process(C+i);
        if(temp < min || min==-1){
            if(temp != -1){
                min = temp;
            }
        }  
    }

    /*
    for(int i=0;i<C+maxCust;i++){
        if(A[i]!=-1)    printf("A[%d] = %d\n",i,A[i]);
    }
    */
    printf("%d", min);

    return 0;
}