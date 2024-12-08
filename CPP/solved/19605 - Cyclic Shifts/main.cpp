#include <iostream>


// checks if T is in S
int _ContainsString(std::string T, std::string S){
    int t=0;
    while(t<=T.length() - S.length()){
        int flg = 1;
        for(int s=0;s<S.length();s++){
            if(T[t+s]!=S[s]){
                flg = 0;
                break;
            }
        }

        if(flg){
            return 1;
        }
        t++;
    }
    return 0;
}


std::string MakeNextCyclic(std::string s){
    char first_c = s[0];
    std::string newStr = s.substr(1);
    newStr.append(1,first_c);
    return newStr;
}


// checks if S's Cyclic string is in T
int DoesContainsCyclic(std::string T, std::string S){
    size_t S_len = S.length();
    
    for(int i=0;i<S_len;i++){
        if(_ContainsString(T,S)){
            return 1;
        }
        S = MakeNextCyclic(S);
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string S, T;

    std::cin >> T >> S;

    if(DoesContainsCyclic(T,S)){
        std::cout << "yes";
    }else{
        std::cout << "no";
    }

    //std::cout << DoesContainsCyclic(T,S)?"yes":"no";
    
    return 0;
}