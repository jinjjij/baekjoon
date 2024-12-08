#include <iostream>



int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    int* arr = (int*)malloc(sizeof(int) * N);

    for(int i=0;i<N;i++){
        std::cin >> arr[i];
    }

    std::qsort(arr, N, sizeof(*arr), cmp);
    int ret[2] = {0,0};
    for(int i=0;i<N;i++){
        if(i<N/2)   ret[0] += arr[i];
        else        ret[1] += arr[i];   
    }

    free(arr);

    std::cout << ret[0] << " " << ret[1];

    return 0;
}