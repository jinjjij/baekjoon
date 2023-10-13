#include <iostream>
#include <set>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    // testcase
    int T = 0;
    std::cin >> T;

    int instNum = 0;
    char inputChar;
    int inputInt;

    for(int t=0;t<T;t++){

        // number of instructions (<= 1,000,000)
        std::cin >> instNum;

        // multiset
        std::multiset<int> mSet;
        // multiset iterators
        std::multiset<int>::iterator iter;
        std::multiset<int>::reverse_iterator riter;

        for(int k=0;k<instNum;k++){
            std::cin >> inputChar;
            std::cin >> inputInt;

            if(inputChar == 'I'){
                mSet.insert(inputInt);
            }else if(inputChar == 'D'){
                // if empty -> next inst
                if(mSet.empty())    continue;

                if(inputInt == 1){
                    iter = mSet.end();
                    iter --;
                    mSet.erase(iter);
                }else if(inputInt == -1){
                    iter = mSet.begin();
                    mSet.erase(iter);
                }else{
                    //error
                }
            }else{
                //error
            }
        }

        // print output
        if(mSet.empty()){
            std::cout << "EMPTY\n";
        }else{
            iter = mSet.begin();
            riter = mSet.rbegin();

            std::cout << *riter << " " << *iter << "\n";
        }


    }
    return 0;
}