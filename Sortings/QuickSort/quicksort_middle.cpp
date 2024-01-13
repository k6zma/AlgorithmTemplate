#include <iostream>
#include <vector>

void QSort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int mid = (left + right) / 2;
    int key = arr[mid];
    int buf;

    while (i <= j) {
        while (arr[i] < key) {
            i++;
        }
        while (arr[j] > key) {
            j--;
        }
        if (i <= j) {
            buf = arr[i];
            arr[i] = arr[j];
            arr[j] = buf;
            i++;
            j--;
        }
    }

    if (left < j) {
        QSort(arr, left, j);
    }

    if (right > i) {
        QSort(arr, i, right);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    QSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}
