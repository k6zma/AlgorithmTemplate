#include <vector>
#include <iostream>

int maxValueOfExpression(const std::vector<int>& a) {
    int n = a.size();
    std::vector<std::vector<int>> d(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        d[i][i] = a[i];
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i; k < j; ++k) {
                d[i][j] = std::max(d[i][j], std::max(d[i][k] + d[k + 1][j], d[i][k] * d[k + 1][j]));
            }
        }
    }

    return d[0][n - 1];
}

int main() {
    std::vector<int> a = {1, 3, 2, 4};

    int result = maxValueOfExpression(a);
    std::cout << "The maximum value of the expression is: " << result;
}