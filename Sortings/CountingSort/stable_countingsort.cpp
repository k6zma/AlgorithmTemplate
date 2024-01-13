#include <iostream>
#include <vector>

void StableCountingSort(const std::vector<int>& A, std::vector<int>& B, int k) {
    std::vector<int> C(k + 1, 0);

    for (int i = 0; i < A.size(); i++) {
        C[A[i]]++;
    }

    for (int j = 1; j <= k; j++) {
        C[j] += C[j - 1];
    }

    for (int i = A.size() - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    StableCountingSort(A, B, k);

    for (int i = 0; i < n; i++) {
        std::cout << B[i] << " ";
    }
}
