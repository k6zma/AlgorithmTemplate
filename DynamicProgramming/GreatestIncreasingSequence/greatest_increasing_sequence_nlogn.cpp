#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int binary_search(const std::vector<int>& d, int item) {
    int left = 0, right = d.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (d[mid] >= item) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

std::vector<int> findLIS(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> d(n + 1, INT_MAX);
    std::vector<int> pos(n + 1), prev(n);
    int length = 0;

    pos[0] = -1;
    d[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        d[i] = INT_MAX;
    }

    for (int i = 0; i < n; ++i) {
        int j = binary_search(d, a[i]);
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            if (j > length) {
                length = j;
                pos[j] = i;
            }
            prev[i] = pos[j - 1];
        }
    }

    std::vector<int> answer;

    int p = pos[length];
    while (p != -1) {
        answer.push_back(a[p]);
        p = prev[p];
    }

    std::reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    std::vector<int> lis = findLIS(a);

    std::cout << "Greatest increasing sequence ";
    for (int i = 0; i < lis.size(); ++i) {
        std::cout << lis[i] << " ";
    }
}
