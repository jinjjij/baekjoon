#include <iostream>
#include <vector>


int rev(int x){
    std::vector<int> arr;
    while(x>0){
        arr.push_back(x%10);
        x /= 10;
    }

    int ret = 0;
    for(int i=0;i<arr.size();i++){
        ret *= 10;
        ret += arr[i];
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int X,Y;
    std::cin >> X >> Y;
    std::cout << rev(rev(X) + rev(Y));
    return 0;
}