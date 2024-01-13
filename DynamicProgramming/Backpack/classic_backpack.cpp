#include <vector>
#include <iostream>

void findAns(int k, int s, int W, std::vector<int> &ans, std::vector<std::vector<int>> &A, std::vector<int> &w, std::vector<int> &p, int &total_weight, int &total_cost) {
    if (A[k][s] == 0) {
        return;
    }

    if (A[k - 1][s] == A[k][s]) {
        findAns(k - 1, s, W, ans, A, w, p, total_weight, total_cost);
    } else {
        findAns(k - 1, s - w[k], W, ans, A, w, p, total_weight, total_cost);
        ans.push_back(k);
        total_weight += w[k];
        total_cost += p[k];
    }
}

int main() {
    int N, W;
    std::cin >> W >> N;
    std::vector<int> w(N + 1), p(N + 1);
    std::vector<std::vector<int>> A(N + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        std::cin >> w[i] >> p[i];
    }

    for (int i = 0; i <= W; ++i) {
        A[0][i] = 0;
    }

    for (int i = 0; i <= N; ++i) {
        A[i][0] = 0;
    }

    for (int k = 1; k <= N; ++k) {
        for (int s = 1; s <= W; ++s) {
            if (s >= w[k]) {
                A[k][s] = std::max(A[k - 1][s], A[k - 1][s - w[k]] + p[k]);
            } else {
                A[k][s] = A[k - 1][s];
            }
        }
    }

    std::vector<int> ans;
    int total_weight = 0, total_cost = 0;
    findAns(N, W, W, ans, A, w, p, total_weight, total_cost);

    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }

    std::cout << "\n";

    std::cout << "Total weight: " << total_weight << "\n";
    std::cout << "Total cost: " << total_cost;
}
