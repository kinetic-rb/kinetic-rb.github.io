#include <iostream>
#include <algorithm>

namespace std {
    template <typename _element_type, typename _Need_Sort_type, typename _Comper>
    inline void insertion_sort(_element_type * arr, const _Need_Sort_type & left, const _Need_Sort_type & right, const _Comper & _comp) {
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
    inline void merge(_element_type * arr, const _Need_Sort_type & l, const _Need_Sort_type & m, const _Need_Sort_type & r, const _Comper & _comp) {
        _element_type * left, * right;
        builder(left, right, r - l + 1);
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
    inline void core(_element_type * arr, const _Need_Sort_type & n, const _Comper & _comp) {
        for (_Need_Sort_type i = 0; i < n; i += 32)
            insertion_sort(arr, i, min((i + 31), (n - 1)), _comp);
        for (_Need_Sort_type size = 32; size < n; size = size << 1) {
            for (_Need_Sort_type Left = 0; Left < n; Left += size << 1) {
                merge(arr, Left, Left + size - 1, min((Left + (size << 1) - 1), (n - 1)), _comp);
            }
        }
    }
    template <typename _element_type, typename _Need_Sort_type>
    inline void core(_element_type * arr, const _Need_Sort_type & n) {
        core(arr, n, [](const _element_type & x, const _element_type & y) {
            return x < y;
        });
    }
    template <typename _element_type, typename _Need_Sort_type, typename _Compare>
    inline void core(_element_type * arr, const _Need_Sort_type & _Ns_S, const _Need_Sort_type & _Ns_E, const _Compare & _comp) {
        for (_Need_Sort_type i = _Ns_S; i < _Ns_E; i += 32)
            insertion_sort(arr, i, min((i + 31), (_Ns_E - 1)), _comp);
        for (_Need_Sort_type size = 32; size < _Ns_E; size = size << 1) {
            for (_Need_Sort_type Left = 0; Left < _Ns_E; Left += size << 1) {
                merge(arr, Left, Left + size - 1, min((Left + (size << 1) - 1), (_Ns_E - 1)), _comp);
            }
        }
    }
}

using namespace std;

int arr[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stable_sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}