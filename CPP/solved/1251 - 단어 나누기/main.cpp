#include <iostream>
#include <algorithm>

std::string process(std::string str, int index1, int index2){
    std::string out = str;
    std::reverse(out.begin(), out.begin() + index1 + 1);
    std::reverse(out.begin() + index1 + 1, out.begin() + index2 + 1);
    std::reverse(out.begin() + index2 + 1, out.end());

    return out;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::cin >> input;
    int size = input.size();

    std::string max = "";
    max.append(size, 'z');

    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            std::string curStr = process(input, i, j);
            if(max > curStr)    max = curStr;
        }
    }
    
    std::cout << max;

    return 0;
}