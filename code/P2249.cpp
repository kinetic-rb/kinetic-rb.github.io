#include <iostream>

using namespace std;

int * ac = new int [1000005];
int n, t, x;

template<typename Type_, typename _element_Type_>
/// this is used to search X's location
inline Type_ multiplication_search(const Type_ &find, const _element_Type_ *arr, int MAX, int MAX_ELEMENT) {
    /// WARNING the array must start with 1 and end with __END__ -> [1, __END__]
    int qloc = 0;
    for(int i = MAX_ELEMENT; i > -1; i--) {
        int loc = qloc + (1 << i);
        if(loc <= MAX && arr[loc] < find) {
            qloc = loc;
        }
    }
    return ++qloc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> ac[i];
    }
    for(; t--; cout << (ac[multiplication_search(x, ac, n, 24)] == x ? multiplication_search(x, ac, n, 29) : -1) << ' ') {
        cin >> x;
    }
    delete[] ac;
    return 0;
}