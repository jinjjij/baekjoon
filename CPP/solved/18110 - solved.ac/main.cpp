#include <iostream>
#include <algorithm>


int iRound(int up, int down){
    int whole = up/down;
    int decimal = up%down;

    if(decimal*2 >= down){
        whole ++;
    }

    return whole;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;
    if(n==0){
        std::cout << 0;
        return 0;
    }

    int arr[n];

    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }

    std::sort(arr, arr+n);

    int cut = iRound(n*3 , 20);
    if(n-(cut*2) <= 0){
        std::cout << 0;
        return 0;
    }

    int sum = 0;

    for(int i=cut; i< n-cut; i++){
        sum += arr[i];
    }

    int avg = iRound(sum, n-(cut*2));
    

    std::cout << avg;
    
    return 0;
}