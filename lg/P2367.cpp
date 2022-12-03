#include <iostream>
#include <algorithm>
#define f(i, n, name) for(long name = i, end ## name = n; name <= end ## name; name++)

using namespace std;

auto _ = [](int & _) -> int {
    char ch = getchar();
    bool bol = false;
    while('0' > ch || ch > '9')
        ch = getchar();
    if(ch == '-') {
        bol = true;
        ch = getchar();
    }
    for(_ = 0; '0' <= ch && ch <= '9'; ch = getchar())
        _ = _ * 10 + ch - 48;
    if(bol)
        _ = -_;
    return _;
};

using namespace std;

int * ac = new int [5000001], * num = new int [5000001];

int main() {
    int n, m, MIN = 0x7fffff;
    _(n);
    _(m);
    f(1, n, i) {
        ac[i] = _(num[i]) - num[i - 1];
    }
    f(0, m - 1, AC) {
        int l, r, c;
        _(l);
        _(r);
        ac[l] += _(c);
        ac[r + 1] -= c;
    }
    f(1, n, i) {
        MIN = min(MIN, ac[i] += ac[i - 1]);
    }
    cout << MIN;
    return 0;
}