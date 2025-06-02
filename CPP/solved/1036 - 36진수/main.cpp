#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<int> sum(60, 0);
    std::vector<std::vector<int>> alphaGain(36, std::vector<int>(60, 0));

    std::string input;
    for (int n = 0; n < N; n++) {
        std::cin >> input;
        int len = input.size();
        for (int i = 0; i < len; ++i) {
            char c = input[len - 1 - i];
            int digit = (c >= 'A') ? (c - 'A' + 10) : (c - '0');

            sum[i] += digit;
            alphaGain[digit][i] += 35 - digit;
        }
    }

    // Carry 처리 for sum
    for (int i = 0; i < 59; ++i) {
        sum[i + 1] += sum[i] / 36;
        sum[i] %= 36;
    }

    // Carry 처리 for alphaGain
    for (int d = 0; d < 36; ++d) {
        for (int i = 0; i < 59; ++i) {
            alphaGain[d][i + 1] += alphaGain[d][i] / 36;
            alphaGain[d][i] %= 36;
        }
    }

    int K;
    std::cin >> K;

    // 정렬: 이득 큰 알파벳부터 선택
    std::vector<int> index(36);
    for (int i = 0; i < 36; ++i) index[i] = i;

    std::sort(index.begin(), index.end(), [&](int a, int b) {
        for (int i = 59; i >= 0; --i) {
            if (alphaGain[a][i] != alphaGain[b][i])
                return alphaGain[a][i] > alphaGain[b][i];
        }
        return false;
    });

    // 상위 K개 알파벳의 이득 적용
    for (int i = 0; i < K; ++i) {
        int d = index[i];
        for (int j = 0; j < 60; ++j) {
            sum[j] += alphaGain[d][j];
            if (sum[j] >= 36) {
                sum[j + 1] += sum[j] / 36;
                sum[j] %= 36;
            }
        }
    }

    // 출력
    bool started = false;
    for (int i = 59; i >= 0; --i) {
        if (!started && sum[i] == 0) continue;
        started = true;
        if (sum[i] < 10) std::cout << (char)(sum[i] + '0');
        else std::cout << (char)(sum[i] - 10 + 'A');
    }

    if (!started) std::cout << '0';
    std::cout << '\n';

    return 0;
}
