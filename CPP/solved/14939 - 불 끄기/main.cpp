#include <iostream>


bool arr[10][10] = {false};


bool _checkBound(int row, int col){
    if(row < 0 || row >= 10 || col < 0 || col >= 10){
        return false;
    }
    return true;
}


void pressSwitch(bool arr[10][10], int row, int col){
    if(_checkBound(row,col))    arr[row][col]   = !arr[row][col];
    if(_checkBound(row-1,col))  arr[row-1][col] = !arr[row-1][col];
    if(_checkBound(row+1,col))  arr[row+1][col] = !arr[row+1][col];
    if(_checkBound(row,col-1))  arr[row][col-1] = !arr[row][col-1];
    if(_checkBound(row,col+1))  arr[row][col+1] = !arr[row][col+1];
}


int process(int offset){
    // copy
    bool copy[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            copy[i][j] = arr[i][j];
        }
    }


    int count = 0;

    int i=0;
    while(offset > 0){
        if(offset%2){
            pressSwitch(copy, 0, i);
            count ++;
        }
        offset -= offset%2;
        offset /= 2;
        i++;
    }

    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            if(copy[i-1][j] == true){
                pressSwitch(copy, i, j);
                count ++;
            }
        }
    }

    for(int i=0;i<10;i++){
        if(copy[9][i])   return -1;
    }

    return count;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);



    char input;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++){
            std::cin >> input;
            if(input == '#'){
                arr[i][j] = false;
            }else{
                arr[i][j] = true;
            }
        }
    }


    int min = 1000;
    for(int i=0;i<1024;i++){
        int out = process(i);
        if(min > out && out != -1){
            min = out;
        }
    }


    std::cout << min;
    
    return 0;
}


