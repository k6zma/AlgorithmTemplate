#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int right, int mid) {
    int it1 = 0, it2 = 0;
    std::vector<int> result(right - left);

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (arr[left + it1] <= arr[mid + it2]) {
            result[it1 + it2] = arr[left + it1];
            it1++;
        } else {
            result[it1 + it2] = arr[mid + it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = arr[left + it1];
        it1++;
    }
    while (mid + it2 < right) {
        result[it1 + it2] = arr[mid + it2];
        it2++;
    }
    for (int i = 0; i < it1 + it2; i++) {
        arr[left + i] = result[i];
    }
}

void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
    if (right - left > 1) {
        int mid = (left + right) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid, right);

        merge(arr, left, right, mid);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    mergeSortRecursive(arr, 0, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}
