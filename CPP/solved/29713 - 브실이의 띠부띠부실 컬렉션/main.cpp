#include <iostream>
#include <vector>


int min(int a, int b){
    return a<b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::string input;

    std::cin >> N;
    std::cin >> input;
    std::vector<int> alphaCount(27, 0);

    for(int i=0;i<input.size();i++){
        alphaCount[input[i] - 'A'] ++;
    }

    int ret = INT32_MAX;
    ret = min(ret, alphaCount['B' - 'A']);
    ret = min(ret, alphaCount['R' - 'A']/2);
    ret = min(ret, alphaCount['O' - 'A']);
    ret = min(ret, alphaCount['N' - 'A']);
    ret = min(ret, alphaCount['Z' - 'A']);
    ret = min(ret, alphaCount['E' - 'A']/2);
    ret = min(ret, alphaCount['S' - 'A']);
    ret = min(ret, alphaCount['I' - 'A']);
    ret = min(ret, alphaCount['L' - 'A']);
    ret = min(ret, alphaCount['V' - 'A']);

    std::cout << ret;

    
    return 0;
}