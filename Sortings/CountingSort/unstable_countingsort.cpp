#include <iostream>
#include <vector>

void SimpleCountingSort(std::vector<int>& A, int k) {
    std::vector<int> C(k + 1, 0);

    for (int i = 0; i < A.size(); i++) {
        C[A[i]] += 1;
    }

    int b = 0;
    for (int j = 0; j <= k; j++) {
        for (int i = 0; i < C[j]; i++) {
            A[b] = j;
            b++;
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    SimpleCountingSort(A, k);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
}
