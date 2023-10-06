#include <iostream>
#include <utility> // pair
#include <deque> // deque



void front2Back(std::deque<int>* mydeque){
    mydeque->push_back(mydeque->front());
    mydeque->pop_front();
}


void back2Front(std::deque<int>* mydeque){
    mydeque->push_front(mydeque->back());
    mydeque->pop_back();
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::deque<int> mydeque;

    // input
    int npos[N+1];
    for(int i=0;i<N;i++){
        std::cin >> npos[i+1];
        mydeque.push_back(i+1);
    }

    int nextpos = 0;

    while(!mydeque.empty()){
        int index = mydeque.front();
        std::cout << index << " ";
        nextpos = npos[index];
        mydeque.pop_front();

        if(nextpos > 0){
            for(int i=0;i<nextpos-1;i++){
                front2Back(&mydeque);
            }
        }else{
            nextpos = -nextpos;
            for(int i=0;i<nextpos;i++){
                back2Front(&mydeque);
            }
        }
    }


    return 0;
}

/*
3 2 1 -3 -1

"1" : 3
2 1 -3 -1 (2)
1 -3 -1 2 (1)
-3 -1 2 1 (0)

"4" : -3
-1 2 1 (3)
1 -1 2 (2)
2 1 -1 (1)
-1 2 1 (0)






*/