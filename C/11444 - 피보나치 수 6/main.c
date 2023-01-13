/*
https://www.acmicpc.net/problem/11444 - 피보나치 수 6
*/


#include <stdio.h>
#include <stdlib.h>

#define NUM 1000000007

typedef struct Matrix {
    int n, m;
    long long int** mat;
} MAT;


MAT* createMatrix(int n, int m){
    MAT* mat = (MAT*)malloc(sizeof(MAT));
    mat->n = n;
    mat->m = m;
    mat->mat = (long long int**)malloc(sizeof(long long int*) * n);
    for(int i=0;i<n;i++){
        mat->mat[i] = (long long int*)malloc(sizeof(long long int) * m);
    }

    return mat;
}   


void destroyMatrix(MAT* mat){
    for(int i=0;i<mat->n;i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}


// ret = m1 * m2;
MAT* MatrixMultiply(MAT* m1, MAT* m2){
    int errFlg = 0;

    if(m1->m != m2->n)  errFlg = 1;

    if(errFlg){
        printf("\nError : multiplyMatrix Error\n");
        printf("matrix dimention not match\n");
    }

    MAT* ret = createMatrix(m1->n, m2->m);
    
    for(int i=0;i<ret->n;i++){
        for(int j=0;j<ret->m;j++){
            ret->mat[i][j] = 0;
            for(int k=0;k<m1->m;k++){
                ret->mat[i][j] += (m1->mat[i][k] * m2->mat[k][j])%NUM;
                ret->mat[i][j] %= NUM;
            }
        }
    }

    return ret;
}


MAT* MatrixExponent(MAT* m, long long int power){
    if(m->m != m->n){
        printf("Error : function matrixExponent\nmatrix dimention error\n");
        return NULL;
    }


    MAT* matrix = createMatrix(m->n, m->n);
    if(power == 0){
        
        for(int i=0;i<m->n;i++){
            for(int j=0;j<m->n;j++){
                if(i==j)    matrix->mat[i][j] = 1;
                else        matrix->mat[i][j] = 0;
            }
        }

        return matrix;
    }
    destroyMatrix(matrix);


    MAT* half = MatrixExponent(m, power/2);
    MAT* ret;
    
    
    if(power % 2){  // 홀수
        MAT* temp = MatrixMultiply(half, half);
        ret = MatrixMultiply(temp, m);
        destroyMatrix(temp);
    }else{
        ret = MatrixMultiply(half, half);
    }

    destroyMatrix(half);
    return ret;
}


int main(void){
    long long int N;
    scanf("%lld", &N);

    MAT* basic = createMatrix(2,2);
    basic->mat[0][0] = 1;
    basic->mat[0][1] = 1;
    basic->mat[1][0] = 1;
    basic->mat[1][1] = 0;

    MAT* exp = MatrixExponent(basic, N-1);
    destroyMatrix(basic);

    MAT* oneZero = createMatrix(2,1);
    oneZero->mat[0][0] = 1;
    oneZero->mat[1][0] = 0;

    MAT* result = MatrixMultiply(exp, oneZero);
    destroyMatrix(oneZero);

    printf("%d", result->mat[0][0]);
    destroyMatrix(result);

    return 0;
}