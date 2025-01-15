#include <iostream>
#include <vector>

#define DPMAX 50

typedef long long int lld;

typedef struct _mat{
    int dim;
    int** value;
} mat;


int dpCheck[DPMAX];
mat* dp[DPMAX];


void debugMat(mat* mat){
    fprintf(stderr, "\n");
    for(int i=0;i<mat->dim;i++){
        for(int j=0;j<mat->dim;j++){
            fprintf(stderr,"%d ", mat->value[i][j]);
        }
        fprintf(stderr,"\n");
    }
}  


mat* createMat(int dim){
    mat* newMat = (mat*) malloc(sizeof(mat));
    newMat->dim = dim;

    newMat->value = (int**) malloc(sizeof(int*) * dim);
    for(int i=0;i<dim;i++){
        newMat->value[i] = (int*) malloc(sizeof(int) * dim);
    }

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            newMat->value[i][j] = 0;
        }
    }

    return newMat;
}


void destroyMat(mat* mat){
    int dim = mat->dim;

    for(int i=0;i<dim;i++){
        free(mat->value[i]);
    }
    free(mat->value);
    free(mat);
}


mat* MultMat(mat* mat1, mat* mat2){
    mat* newMat = createMat(mat1->dim);

    for(int i=0;i<mat1->dim;i++){
        for(int j=0;j<mat1->dim;j++){
            for(int k=0;k<mat1->dim;k++){
                newMat->value[i][j] += mat1->value[i][k] * mat2->value[k][j];
                newMat->value[i][j] %= 1000;
            }
        }
    }

    return newMat;
}


// origin을 free하지 않는다.
mat* dupMat(mat* origin){
    mat* newMat = createMat(origin->dim);
    for(int i=0;i<origin->dim;i++){
        for(int j=0;j<origin->dim;j++){
            newMat->value[i][j] = origin->value[i][j];
        }
    }

    return newMat;
}


mat* createIdentity(int dim){
    mat* newMat = createMat(dim);
    for(int i=0;i<dim;i++){
        newMat->value[i][i] = 1;
    }

    return newMat;
}


mat* SquareMat(mat* inputMat, lld times){
    
//    fprintf(stderr, "squreMat(matrix, %ld) : start\n", times);
//    fprintf(stderr, "inputmat : ");debugMat(inputMat);
    
    

    mat* outputMat = dupMat(inputMat);

    if(times == 0){
        return createIdentity(inputMat->dim);
    }else if(times == 1){
        return outputMat;
    }
    
    lld tmp = 1;
    int jisu = 0;

    // 2 ^ times = tmp
    while(tmp*2 < times){
        tmp *= 2;
        jisu ++;
    }

    // dp데이터에 없는 2제곱행렬 -> 만들어 넣어줌..
    if(dpCheck[jisu] == 0){ 
        dp[jisu] = SquareMat(inputMat, tmp);
        dpCheck[jisu] = 1;
    }

    // 이제 dp에 있음

    // tmp * 나머지 
    mat* mat1 = SquareMat(inputMat, times - tmp);
    outputMat = MultMat(mat1, dp[jisu]);
//    debugMat(mat1);


//    fprintf(stderr, "squreMat(matrix, %ld) : end\n", times);
//    fprintf(stderr, "outputmat : "); debugMat(outputMat);
    return outputMat;
}


 


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    lld b = 0;

    std::cin >> n >> b;

// 입력행렬 할당당
    mat* inputMat = createMat(n);

// dp를 위한 check 배열 초기화화
    for(int i=0;i<DPMAX;i++){
        dpCheck[i] = 0;
    }

// 행렬 input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> inputMat->value[i][j];
        }
    }

// 제곱 처리 후 result 에 할당
    mat* result = SquareMat(inputMat, b);

// 1000으로 마지막으로 나눠버리기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result->value[i][j] %= 1000;
        }
    }

// 출력
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout << result->value[i][j] << " ";
        }
        std::cout << "\n";
    }

// Free
    destroyMat(inputMat);
    for(int i=0;i<DPMAX;i++){
        if(dpCheck[i])  destroyMat(dp[i]);
    }
    
    return 0;
}