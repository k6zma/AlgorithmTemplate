#include <iostream>
#include <vector>

int digit(int x, int i) {
    while (i-- > 1) {
        x /= 10;
    }
    return x % 10;
}

void radixSort(std::vector<int>& A, int m, int k) {
    std::vector<int> B(A.size());
    std::vector<int> C(k);

    for (int i = 1; i <= m; i++) {
        std::fill(C.begin(), C.end(), 0);

        for (int j = 0; j < A.size(); j++) {
            int d = digit(A[j], i);
            C[d]++;
        }

        int count = 0;
        for (int j = 0; j < k; j++) {
            int tmp = C[j];
            C[j] = count;
            count += tmp;
        }

        for (int j = 0; j < A.size(); j++) {
            int d = digit(A[j], i);
            B[C[d]] = A[j];
            C[d]++;
        }

        for (int j = 0; j < A.size(); j++) {
            A[j] = B[j];
        }
    }
}

int main() {
    std::vector<int> A = {329, 457, 657, 839, 436, 720, 355};
    int k = 10;
    int m = 3;

    radixSort(A, m, k);

    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
}
