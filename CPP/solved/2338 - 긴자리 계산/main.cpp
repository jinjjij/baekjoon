#include <iostream>
#include <vector>
#include <string>


class bigInt{
    int digit;
    bool sign;
    std::vector<int> num;

    static const int BASE = 100000000; // 10^8
    static const int WIDTH = 8;

public:
    bigInt(std::string input) {
        sign = true;
        if (input.empty()) {
            digit = 1;
            num.push_back(0);
            return;
        }

        // 부호 확인
        if (input[0] == '-') {
            sign = false;
            input = input.substr(1);
        } else if (input[0] == '+') {
            input = input.substr(1);
        }

        // 숫자만 남았을 때 처리
        for (int i = input.size(); i > 0; i -= WIDTH) {
            int start = std::max(0, i - WIDTH);
            int len = i - start;
            num.push_back(std::stoi(input.substr(start, len)));
        }

        // 총 자릿수 계산
        digit = input.size();

        // 불필요한 앞자리 0 제거
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();

        // 0이면 양수 처리
        if (num.size() == 1 && num[0] == 0)
            sign = true;
    }

    std::string toString() {
        if (num.empty()) return "0";

        std::string result;

        if (!sign) result += '-';

        // 가장 높은 자리 수는 그대로 붙임
        result += std::to_string(num.back());

        // 나머지는 앞을 0으로 채움
        for (int i = num.size() - 2; i >= 0; --i) {
            std::string part = std::to_string(num[i]);
            // 앞을 0으로 채워서 WIDTH 길이로 맞춤
            result += std::string(WIDTH - part.length(), '0') + part;
        }

        return result;
    }


    // 두 숫자의 절댓값 덧셈
    std::vector<int> absAdd(const std::vector<int>& a, const std::vector<int>& b) {
        std::vector<int> res;
        int carry = 0, n = std::max(a.size(), b.size());
        for (int i = 0; i < n || carry; ++i) {
            long long temp = carry;
            if (i < a.size()) temp += a[i];
            if (i < b.size()) temp += b[i];
            res.push_back(temp % BASE);
            carry = temp / BASE;
        }
        return res;
    }

    // 두 숫자의 절댓값 뺄셈 (a >= b 가정)
    std::vector<int> absSub(const std::vector<int>& a, const std::vector<int>& b) {
        std::vector<int> res;
        int borrow = 0;
        for (int i = 0; i < a.size(); ++i) {
            long long temp = a[i] - borrow - (i < b.size() ? b[i] : 0);
            if (temp < 0) {
                temp += BASE;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.push_back(temp);
        }
        // 불필요한 0 제거
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        return res;
    }

    // 절댓값 비교: a > b → 1, a == b → 0, a < b → -1
    int absCmp(const std::vector<int>& a, const std::vector<int>& b) {
        if (a.size() != b.size()) return a.size() > b.size() ? 1 : -1;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i])
                return a[i] > b[i] ? 1 : -1;
        }
        return 0;
    }


    void Add(bigInt other) {
        if (sign == other.sign) {
            num = absAdd(num, other.num);
        } else {
            int cmp = absCmp(num, other.num);
            if (cmp >= 0) {
                num = absSub(num, other.num);
            } else {
                num = absSub(other.num, num);
                sign = other.sign;
            }
        }

        // 0 처리
        if (num.size() == 1 && num[0] == 0)
            sign = true;
    }

    void Sub(bigInt other) {
        other.sign = !other.sign;
        Add(other);
    }

    // 곱셈 (절댓값 곱한 후, 부호 처리)
    void Mult(bigInt other) {
        std::vector<int> res(num.size() + other.num.size());

        for (int i = 0; i < num.size(); ++i) {
            long long carry = 0;
            for (int j = 0; j < other.num.size() || carry; ++j) {
                long long cur = res[i + j] +
                    1LL * num[i] * (j < other.num.size() ? other.num[j] : 0) + carry;
                res[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }

        // 불필요한 0 제거
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();

        num = res;
        sign = (sign == other.sign);

        // 0 처리
        if (num.size() == 1 && num[0] == 0)
            sign = true;
    }
};



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string aStr, bStr;
    std::cin >> aStr >> bStr;

    bigInt B(bStr);

    bigInt ADD(aStr);
    bigInt SUB(aStr);
    bigInt MULT(aStr);

    ADD.Add(B);
    SUB.Sub(B);
    MULT.Mult(B);

    std::cout << ADD.toString() << "\n" << SUB.toString() << "\n" << MULT.toString() << "\n";
    
    return 0;
}