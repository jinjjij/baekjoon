/*
https://www.acmicpc.net/problem/5373
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct _cube{
    char U[9];
    char D[9];
    char F[9];
    char B[9];
    char L[9];
    char R[9];
} CUBE;


void rotateFace(char* face, char dir){
    int prev[9];
    for(int i=0;i<9;i++){
        prev[i] = face[i];
    }
    if(dir=='+'){
        face[0] = prev[6];
        face[1] = prev[3];
        face[2] = prev[0];
        face[3] = prev[7];
        face[5] = prev[1];
        face[6] = prev[8];
        face[7] = prev[5];
        face[8] = prev[2];
    }else if(dir == '-'){
        face[6] = prev[0];
        face[3] = prev[1];
        face[0] = prev[2];
        face[7] = prev[3];
        face[1] = prev[5];
        face[8] = prev[6];
        face[5] = prev[7];
        face[2] = prev[8];
    }else{
        fprintf(stderr, "error : rotateFace\n");
    }
}

/*
0   3   6   9   0
1   4   7   10  1
2   5   8   11  2
*/
void rotateSide(char dir,
                char* a1, char* a2, char* a3, char* a4, char* a5, char* a6, 
                char* a7, char* a8, char* a9, char* a10, char* a11, char* a12){
    
    int prev[13] = {0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12};

    if(dir == '+'){
        *a1 = prev[10];  *a4 = prev[1];  *a7 = prev[4];  *a10 = prev[7];
        *a2 = prev[11];  *a5 = prev[2];  *a8 = prev[5];  *a11 = prev[8];
        *a3 = prev[12];  *a6 = prev[3];  *a9 = prev[6];  *a12 = prev[9];
    }else if(dir == '-'){
        *a1 = prev[4];  *a4 = prev[7];  *a7 = prev[10];  *a10 = prev[1];
        *a2 = prev[5];  *a5 = prev[8];  *a8 = prev[11];  *a11 = prev[2];
        *a3 = prev[6];  *a6 = prev[9];  *a9 = prev[12];  *a12 = prev[3];
    }
}


void rotate(CUBE* cube, char face, char dir){
    char* U = cube->U;
    char* D = cube->D;
    char* F = cube->F;
    char* B = cube->B;
    char* L = cube->L;
    char* R = cube->R;
    switch (face){
    case 'U':
        rotateFace(U,dir);
        rotateSide(dir, &B[2], &B[1], &B[0],
                        &R[2], &R[1], &R[0],
                        &F[2], &F[1], &F[0],
                        &L[2], &L[1], &L[0]);
        break;
    case 'D':
        rotateFace(D,dir);
        rotateSide(dir, &F[6], &F[7], &F[8],
                        &R[6], &R[7], &R[8],
                        &B[6], &B[7], &B[8],
                        &L[6], &L[7], &L[8]);
        break;
    case 'F':
        rotateFace(F,dir);
        rotateSide(dir, &U[6], &U[7], &U[8],
                        &R[0], &R[3], &R[6],
                        &D[2], &D[1], &D[0],
                        &L[8], &L[5], &L[2]);
        break;
    case 'B':
        rotateFace(B,dir);
        rotateSide(dir, &U[2], &U[1], &U[0],
                        &L[0], &L[3], &L[6],
                        &D[6], &D[7], &D[8],
                        &R[8], &R[5], &R[2]);
        break;
    case 'L':
        rotateFace(L,dir);
        rotateSide(dir, &U[0], &U[3], &U[6],
                        &F[0], &F[3], &F[6],
                        &D[0], &D[3], &D[6],
                        &B[8], &B[5], &B[2]);
        break;
    case 'R':
        rotateFace(R,dir);
        rotateSide(dir, &U[8], &U[5], &U[2],
                        &B[0], &B[3], &B[6],
                        &D[8], &D[5], &D[2],
                        &F[8], &F[5], &F[2]);
        break;
    default:
        fprintf(stderr, "Error\b");
        break;
    }
}


void printUp(CUBE* cube){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",cube->U[i*3+j]);
        }
        printf("\n");
    }
}


CUBE* createCube(void){
    CUBE* cube = (CUBE*)malloc(sizeof(CUBE));
    for(int i=0;i<9;i++){
        cube->U[i] = 'w';
        cube->D[i] = 'y';
        cube->F[i] = 'r';
        cube->B[i] = 'o';
        cube->L[i] = 'g';
        cube->R[i] = 'b';
    }

    return cube;
}


void destroyCube(CUBE* cube){
    free(cube);
}


int main(void){
    int T;
    scanf("%d", &T);
    CUBE* cube;
    int N;
    char face;
    char dir;
    char buf[3];

    for(int t=0;t<T;t++){
        CUBE* cube = createCube();
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            scanf("%s",buf);
            face = buf[0];
            dir  = buf[1];

            rotate(cube, face, dir);
        }

        printUp(cube);

        destroyCube(cube);
    }
    return 0;
}