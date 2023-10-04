#include <iostream>
#include <stack>
#include <queue>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::stack<int> stack;
    std::queue<int> input_queue;
    std::cin >> N;


    for(int i=0;i<N;i++){
        int input;
        std::cin >> input;
        input_queue.push(input);
    }

    int next = 1;

    while(!stack.empty() || !input_queue.empty()){
        bool empty_q = input_queue.empty();
        bool empty_s = stack.empty();
        int input = 0;
        if(!empty_q)    input = input_queue.front();
        int top = 0;
        if(!empty_s)    top = stack.top(); 

        if(next == input){
            next ++;
            input_queue.pop();
        }
        else if(next == top){
            next ++;
            stack.pop();
        }
        else if(!empty_q){
            stack.push(input);
            input_queue.pop();
        }else{
            break;
        }
    }

    if(next == N+1){
        std::cout << "Nice\n";
    }else{
        std::cout << "Sad\n";
    }
    return 0;
}