#include <iostream>


int gcd(int a, int b){
    if(a<b){
        int tmp = b;
        b = a;
        a = tmp;
    }

    // now a > b
    while(1){
        if(a%b == 0){
            return b;
        }

        int c = a%b;
        a = b;
        b = c;
    }
    
}   


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    for(int i=0;i<n;i++){
        int a, b;
        std::cin >> a >> b;
        int g = gcd(a,b);
        std::cout << a/g << " " << b/g << "\n";
    }

    return 0;
}