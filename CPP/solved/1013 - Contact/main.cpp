#include <iostream>
#include <regex>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::regex pattern(R"((100+1+|01)+)"); // Raw string 사용으로 백슬래시 이슈 회피
    int T;
    std::cin >> T;

    while (T--) {
        std::string s;
        std::cin >> s;

        if (std::regex_match(s, pattern)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}