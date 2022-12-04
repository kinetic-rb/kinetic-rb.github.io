#include <algorithm>
#include <iostream>
#include <ctime>

template <typename _element_type, typename _Need_Sort_type, typename _Comper>
void insertionSort(_element_type * arr, _Need_Sort_type left, _Need_Sort_type right, const _Comper & _comp) {
    for (_Need_Sort_type i = left + 1; i <= right; i++) {
        auto temp = arr[i];
        auto j = i - 1;
        while (!_comp(arr[j], temp) && j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

template <typename _element_type, typename _size_type>
inline void builder(_element_type * & left, _element_type * & right, const _size_type & size) {
    left = new _element_type [size];
    right = new _element_type [size];
}

template <typename _element_type>
inline void del(_element_type * & left, _element_type * & right) {
    delete[] left;
    delete[] right;
}

template <typename _element_type, typename _Need_Sort_type, typename _Comper>
inline void merge(_element_type * arr, _Need_Sort_type l, _Need_Sort_type m, _Need_Sort_type r, const _Comper & _comp) {
    _element_type * left, * right;
    builder(left, right, 100005);
    _Need_Sort_type len1 = m - l + 1, len2 = r - m;
    for (_Need_Sort_type i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (_Need_Sort_type i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    auto i = 0, j = 0;
    auto k = l;
    while (i < len1 && j < len2)
        (_comp(left[i], right[j])) ? arr[k++] = left[i++] : arr[k++] = right[j++];
    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];
    del(left, right);
}

template <typename _element_type, typename _Need_Sort_type, typename _Comper>
inline void merti_sort(_element_type * arr, _Need_Sort_type n, const _Comper & _comp) {
    for (_Need_Sort_type i = 0; i < n; i += 32)
        insertionSort(arr, i, std::min((i + 31), (n - 1)), _comp);
    for (_Need_Sort_type size = 32; size < n; size = size << 1) {
        for (_Need_Sort_type Left = 0; Left < n; Left += size << 1) {
            merge(arr, Left, Left + size - 1, std::min((Left + (size << 1) - 1), (n - 1)), _comp);
        }
    }
}

int n, m;

struct AC {
    int mark[10];
} ac[100000];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(register int i = 0; i < n; i++) {
        for(register int j = 0; j < m; j++)
            cin >> ac[i].mark[j];
    }
    merti_sort(ac, n, [](const AC & i, const AC & j) {
        for(register int k = 0; k < m; k++) {
            if(i.mark[k] != j.mark[k])
                return i.mark[k] > j.mark[k];
        }
        return false;
    });
    for(register int i = 0; i < n; i++) {
        for(register int j = 0; j < m; j++)
            cout << ac[i].mark[j] << ' ';
        cout << '\n';
    }
    return 0;
}