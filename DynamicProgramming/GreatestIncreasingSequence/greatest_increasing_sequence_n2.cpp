#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findLIS(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> prev(n, -1);
    std::vector<int> d(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int length = d[0];
    for (int i = 0; i < n; ++i) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    std::vector<int> answer;
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = prev[pos];
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
