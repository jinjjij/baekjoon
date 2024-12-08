#include <iostream>






int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a,b,c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    // firstline

    std::cout << a+b-c << "\n";

    // secondline

    int output = a;

    if (b>=1000){
        output *= 10000;
    }else if( b >= 100 ){
        output *= 1000;
    }else if ( b >= 10 ){
        output *= 100;
    }else {
        output *= 10;
    }

    output += b;
    output -= c;

    std::cout << output;
    return 0;
}