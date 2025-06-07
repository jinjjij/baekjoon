#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::string output;

    output.append(N-1, ' ');
    output += "*\n";

    for(int i=1;i<N;i++){
        output.append(N-i-1, ' ');
        output += '*';
        output.append(i*2-1, ' ');
        output += "*\n";
    }

    std::cout << output;
    
    return 0;
}