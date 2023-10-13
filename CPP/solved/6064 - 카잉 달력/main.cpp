#include <iostream>
#include <numeric>



int gcd(int x, int y){
    if(y == 0)  return x;
    else        return gcd(y, x%y);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int m,n,x,y;
    int result = -1;

    int T = 0;
    std::cin >> T;
    for(int t=0;t<T;t++){
        result = -1;

        std::cin >> m;
        std::cin >> n;
        std::cin >> x;
        std::cin >> y;

        for(int p=x;p<=lcm(m,n);p+=m){
            if((n!=y && p%n == y) || (n==y && p%n == 0)){
                result = p;
                break;
            }
        }

        std::cout << result << '\n';
    }
    
    return 0;
}