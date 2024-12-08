#include <iostream>


std::string VoteCounter(std::string vote_string){
    int y = 0;  // yes
    int n = 0;  // no
    int p = 0;  // present
    int a = 0;  // absent
    int count = 0;

    for(auto &ch : vote_string){
        count++;
        switch(ch){
            case 'Y':   y++;    break;
            case 'N':   n++;    break;
            case 'P':   p++;    break;
            case 'A':   a++;    break;
            default :   break;
        }
    }

    // If at least half of the members were absent, respond "need quorum"
    if(a > count/2 || (a == count/2 && count%2==0)){
        return "need quorum";
    }
    // If there are more yes than no votes, respond "yes"
    if(y>n){
        return "yes";
    }
    // If there are more no than yes votes, respond "no"
    if(n>y){
        return "no";
    }
    // If there are the same number of yes and no votes, respond "tie"
    if(y == n){
        return "tie";
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input_string = "";

    while(1){
        std::cin >> input_string;
        if(input_string == "#") break;
        std::cout << VoteCounter(input_string) << "\n";
    }

    return 0;
}