#include <vector>
#include <iostream>
#include <string>

std::pair<int, std::string> maxValueOfExpression(const std::vector<int>& a) {
    int n = a.size();
    std::vector<std::vector<int>> d(n, std::vector<int>(n));
    std::vector<std::vector<std::string>> expr(n, std::vector<std::string>(n));

    for (int i = 0; i < n; ++i) {
        d[i][i] = a[i];
        expr[i][i] = std::to_string(a[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i; k < j; ++k) {
                int sum = d[i][k] + d[k + 1][j];
                int product = d[i][k] * d[k + 1][j];
                if (sum > d[i][j]) {
                    d[i][j] = sum;
                    expr[i][j] = "(" + expr[i][k] + "+" + expr[k + 1][j] + ")";
                }
                if (product > d[i][j]) {
                    d[i][j] = product;
                    expr[i][j] = "(" + expr[i][k] + "*" + expr[k + 1][j] + ")";
                }
            }
        }
    }

    return {d[0][n - 1], expr[0][n - 1]};
}

int main() {
    std::vector<int> a = {1, 3, 2, 4};

    std::pair<int, std::string> result = maxValueOfExpression(a);
    std::cout << "The maximum value of the expression is: " << result.first << "\n";
    std::cout << "The expression is: " << result.second;
}