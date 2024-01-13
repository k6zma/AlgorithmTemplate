#include <iostream>
#include <vector>

void buildGrayCode(int n, std::vector<std::vector<char>> &grayCode) {
    grayCode[0][n - 1] = '0';
    grayCode[1][n - 1] = '1';

    int p = 2;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < p; j++) {
            grayCode[p + j] = grayCode[p - j - 1];
        }

        for (int j = 0; j < p; j++) {
            grayCode[j][n - i] = '0';
        }

        for (int j = 0; j < p; j++) {
            grayCode[p + j][n - i] = '1';
        }

        p *= 2;
    }
}

int main() {
    int n;
    std::cin >> n;

    int temp = 1 << n;

    std::vector<std::vector<char>> grayCode(temp, std::vector<char>(n, '0'));

    buildGrayCode(n, grayCode);

    for (int i = 0; i < grayCode.size(); i++) {
        for (int j = 0; j < grayCode[i].size(); j++) {
            std::cout << grayCode[i][j];
        }
        std::cout << "\n";
    }
}