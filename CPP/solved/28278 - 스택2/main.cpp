#include <iostream>
#include <stack>




int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::stack<int> stack;
    int inst = 0;
    int input = 0;

    std::cin >> N;
    for(int i=0;i<N;i++){
        std::cin >> inst;

        switch(inst){
            case 1 :
                std::cin >> input;
                stack.push(input);
                break;
            case 2 : 
                if(stack.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << stack.top() << '\n';
                    stack.pop();
                }
                break;
            case 3 :
                std::cout << stack.size() << '\n';
                break;
            case 4 : 
                std::cout << stack.empty() ? 1 : 0;
                std::cout << '\n';
                break;
            case 5 :
                if(stack.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << stack.top() << '\n';
                }
                break; 
            default:
                break;
        }
    }

    
    return 0;
}