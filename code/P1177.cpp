#include <algorithm>
#include <iostream>
#include <ctime>

void insertionSort(int * arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int left[2000000], right[2000000];
inline void merge(int * arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k++] = left[i++];
    }
    while (j < len2) {
        arr[k++] = right[j++];
    }
}

template <typename _element_type, typename _Need_Sort_type>
inline void timSort(_element_type * arr, _Need_Sort_type n) {
    for (_Need_Sort_type i = 0; i < n; i += 32)
        insertionSort(arr, i, std::min((i + 31), (n - 1)));
    for (_Need_Sort_type size = 32; size < n; size = size << 1) {
        for (_Need_Sort_type Left = 0; Left < n; Left += size << 1) {
            merge(arr, Left, Left + size - 1, std::min((Left + (size << 1) - 1), (n - 1)));
        }
    }
}

// Driver program to test above function

int arr[2110000];

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    timSort(arr, n);
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    return 0;
}