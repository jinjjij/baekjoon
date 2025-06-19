#include <iostream>
#include <vector>
#include <stack>


int _score(char c){
    if(c == '+' || c == '-')    return 1;
    if(c == '*' || c == '/')    return 2;
    return 0;
}


int priority(char a, char b){
    return _score(a) - _score(b);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::cin >> input;

    std::stack<char> stack;
    std::string output;
    for(int i=0;i<input.size();i++){
        char c = input[i];

        if(c >= 'A' && c <= 'Z'){
            output.push_back(c);
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(!stack.empty() && stack.top() != '(' && priority(stack.top(), c) >= 0){
                output.push_back(stack.top());
                stack.pop();
            }
            stack.push(c);
        }else if(c == '('){
            stack.push(c);
        }else if(c == ')'){
            while(!stack.empty() && stack.top() != '('){
                output.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        }
    }
    while(!stack.empty()){
        output.push_back(stack.top());
        stack.pop();
    }

    std::cout << output;
    
    return 0;
}