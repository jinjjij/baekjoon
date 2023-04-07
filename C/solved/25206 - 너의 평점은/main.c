/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int processStr(char* str, int sLen, float* M, float* S){
    char *ptr = strtok(str, " ");   //subject string

    ptr = strtok(NULL, " ");        // 4.0
    float a = (float)atoi(ptr);
    *M = a;

    ptr = strtok(NULL, " ");        // A+

    char alpha = ptr[0];
    char sign = ptr[1];

    if(sign == 0){  // P or F
        if(alpha == 'P'){
            return 0;
        }else{
            *S = 0;
            return 1;
        }
    }

    float temp = 0;
    switch (alpha)
    {
        case 'A':
            temp = 4;
            break;
    
        case 'B':
            temp = 3;
            break;

        case 'C':
            temp = 2;
            break;

        case 'D':
            temp = 1;
            break;

        default:
            break;
    }

    if(sign == '+'){
        temp += 0.5;
    }
 
    *S = temp * (float)a;

    //printf("*M = %f, *S = %f\n", *M, *S);

    return 1;
}


int main(void){
    char tmpStr[100];
    float sum_M = 0;
    float sum_S = 0;
    float M = 0;
    float S = 0;

    for(int i=0;i<20;i++){
        gets(tmpStr);
        if(processStr(tmpStr, strlen(tmpStr), &M, &S)){
            sum_M += M;
            sum_S += S;
        }
    }

    printf("%.6f", sum_S / sum_M);
    return 0;
}