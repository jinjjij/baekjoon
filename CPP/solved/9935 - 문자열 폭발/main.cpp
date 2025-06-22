#include <iostream>
#include <vector>
#include <string>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::string sub;

    std::cin >> input;
    std::cin >> sub;
    std::string stack;
    stack.reserve(input.size());

    char subLast = sub[sub.size()-1];
    int index = 0;

    for(int i=0;i<input.size();i++){
        stack.push_back(input[i]);
        index ++;
        if(index < sub.size())  continue;

        if(stack[index-1] == subLast){
            if(stack.compare(index-sub.size(), sub.size(), sub) == 0){
                stack.erase(index-sub.size(), sub.size());
                index -= sub.size();
            }
        }
    }

    if(stack.empty())   std::cout << "FRULA";
    else                std::cout << stack;
    
    
    return 0;
}