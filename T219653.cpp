#include <bits/stdc++.h>
using namespace std;

template <typename _type1, typename type_of_n, typename _type2, typename _type3, typename _type4, typename _Compare>
inline void merger(register _type1 * A, register const _type2 * L, register _type3 leftCount, const register _type4 * R, type_of_n register rightCount, register _Compare comper) {
    register auto i = 0, j = 0, k = 0;
    while (i < leftCount && j < rightCount) {
        (comper(L[i], R[j])) ? A[k++] = L[i++] : A[k++] = R[j++];
    }
    while (i < leftCount)
        A[k++] = L[i++];
    while (j < rightCount)
        A[k++] = R[j++];
}

template <typename _type, typename type_of_n, typename _Compare>
inline void merge(register _type * A, register const type_of_n & n, register _Compare comper) {
    if (n < 2)
        return;
    register auto mid = n / 2, i = 0;
    register auto * L = new _type[mid], * R = new _type[n - mid];
    for (i = 0; i < mid; i++)
        L[i] = A[i];
    for (i = mid; i < n; i++)
        R[i - mid] = A[i];
    merge(L, mid, comper);
    merge(R, n - mid, comper);
    merger(A, L, mid, R, n - mid, comper);
}

using namespace std;

int n, m;

struct AC {
    int * mark = new int [10];
} ac[100000];

inline bool cmp(const AC & i, const AC & j) {
    for(register int k = 0; k < m; k++) {
        if(i.mark[k] != j.mark[k])
            return i.mark[k] > j.mark[k];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(register int i = 0; i < n; i++) {
        for(register int j = 0; j < m; j++)
            cin >> ac[i].mark[j];
    }
    merge(ac, n, cmp);
    for(register int i = 0; i < n; i++) {
        for(register int j = 0; j < m; j++)
            cout << ac[i].mark[j] << ' ';
        cout << '\n';
    }
    return 0;
}