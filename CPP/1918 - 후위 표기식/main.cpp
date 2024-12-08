#include <iostream>


bool _isAplha(char c){
    if(c>='A' && c<='Z'){
        return true;
    }else{
        return false;
    }
}


/*
    add a () to string
    ex. A+B*C-D/E -> A+(B*C)-(D/E) -> (A+(B*C))-(D/E)
*/
std::string scopify(std::string str){
    
}   


std::string _process(std::string str){
    //fprintf(stderr, "processing : %s\n", str.c_str());
    if(str[0] == '(' && str[str.length()-1] == ')'){
        return _process(str.substr(1,str.length()-2));
    }

    // 1. 가장 바깥쪽 괄호인지 확인
    // 2. +- 우선 */ 나중

    // 처리할 기호를 찾는다.
    int scope_lev = 0;
    int separate_pos = -1;
    char separate_ch = ' ';
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            scope_lev ++;
        }else if(str[i] == ')'){
            scope_lev --;
        }


        if(scope_lev == 0){
            if((str[i] == '+' || str[i] == '-') && (separate_ch == '*' || separate_ch=='/' || separate_ch==' ')){
                separate_pos = i;
                separate_ch = str[i];
            }else if((str[i] == '*' || str[i] == '/') && separate_ch == ' '){
                separate_pos = i;
                separate_ch = str[i];
            }
        }
    }

    if(separate_pos == -1 || separate_ch == ' '){
        return str;
    }else{
        return _process(str.substr(0,separate_pos)) + _process(str.substr(separate_pos+1,str.length() -separate_pos-1)) + separate_ch;
    }
}


std::string postfix(std::string str){
    return _process(str);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string inputstr;
    std::cin >> inputstr;
    std::cout << postfix(scopify(inputstr));
    
    return 0;
}


/*
p(A+B*C-D/E)
= p(A) p(B*C-D/E) +
= A p(B*C) p(D/E) - +
= A B C * D E / - +
= ABC*DE/-+

= p(A+B*C)-p(D/E)
= p(A)p(B*C)+-DE/
= ABC*+-DE/

= p(A)p(B*C)+

(A+(B*C))-(D/E)
p(A+(B*C)) p(D/E) -
p(A) p(B*C) + D E / -
A B C * + D E / -


A*B*C
AB**C
AB*C*


A + ((B*C)-(D/E))

= A p(B*C-D/E) +
= A B*C D/E - +
= A B C * D E / - +

A*B*C
A*(B*C)
A*BC*
ABC**


(A*B) * C
AB**C
AB*C*


*/