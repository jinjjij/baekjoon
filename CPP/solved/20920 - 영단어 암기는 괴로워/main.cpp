#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::vector<std::string> strVec;
    std::map<std::string, int> strMap; 

    std::cin >> N >> M;

    std::string inputStr;
    for(int i=0;i<N;i++){
        std::cin >> inputStr;

        // check length of input string
        if(inputStr.length() >= M){
            // check if word is already in strMap
            if(strMap.count(inputStr) > 0){
                strMap[inputStr] ++;
            }else{
                strMap[inputStr] = 1;
                strVec.push_back(inputStr);
            }         
        }
    }

    // sort
    std::sort(strVec.begin(), strVec.end(), [&strMap](std::string &a, std::string &b){
        // 1. 자주 나오는 단어일수록 앞에 배치한다.
        if(strMap[a] != strMap[b]){
            if(strMap[a] > strMap[b]){
                return 1;
            }else{
                return 0;
            }
        }
        // 2. 해당 단어의 길이가 길수록 앞에 배치한다.
        else if(a.length() != b.length()){
            if(a.length() > b.length()){
                return 1;
            }else{
                return 0;
            }
        }

        // 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다.
        else if(a.compare(b) < 0){
            return 1;
        }else if(a.compare(b) > 0){
            return 0;
        }

    });

    // output
    for(auto i : strVec){
        std::cout << i << "\n";
    }

    
    return 0;
}