#include <iostream>
#include <vector>


int max(int a, int b){
    return a>b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::vector<int> arr(N);

    for(int i=0;i<N;i++){
        std::cin >> arr[i];
    }


    // dp arr
    std::vector<int> ascDp(N, 1);
    std::vector<int> dscDp(N, 1);

    for(int i=0;i<N;i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                ascDp[i] = max(ascDp[j]+1, ascDp[i]);
            }
        }
    }


    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>i;j--){
            if(arr[j] < arr[i]){
                dscDp[i] = max(dscDp[j]+1, dscDp[i]);   
            }
        }
    }

 
    // i = 상승/하강 구분점
    // 0-i : 상승수열
    // i ~ N-1 : 하강수열
    int ret = 0;
    for(int i=0;i<N;i++){
        ret = max(ret, ascDp[i] + dscDp[i] - 1);
    }

    std::cout << ret;

    return 0;
}

