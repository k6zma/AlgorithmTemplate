#include <iostream>
#include <vector>
#include <algorithm>

const int k = 10;
const int m = 10;

int digit(int number, int d) {
    while (d-- > 1) {
        number /= 10;
    }
    return number % 10;
}

void radixSort(std::vector<int>& A, int l, int r, int d, std::vector<int>& c) {
    if (d > m || l >= r) {
        return;
    }

    std::vector<int> cnt(k + 1, 0);

    for (int i = l; i <= r; i++) {
        int j = digit(A[i], d);
        cnt[j + 1]++;
    }

    for (int j = 2; j <= k; j++) {
        cnt[j] += cnt[j - 1];
    }

    for (int i = r; i >= l; i--) {
        int j = digit(A[i], d);
        c[l + cnt[j]] = A[i];
        cnt[j]--;
    }

    for (int i = l; i <= r; i++) {
        A[i] = c[i];
    }

    radixSort(A, l, l + cnt[0] - 1, d + 1, c);
    for (int i = 1; i <= k; i++) {
        radixSort(A, l + cnt[i - 1], l + cnt[i] - 1, d + 1, c);
    }
}

int main() {
    std::vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> c(A.size());

    radixSort(A, 0, A.size() - 1, 1, c);

    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
}
