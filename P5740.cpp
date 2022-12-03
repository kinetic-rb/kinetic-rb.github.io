#include <iostream>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int chinese, math, english, tot;
    student() {
        tot = 0;
    }
} st[1005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i].name >> st[i].chinese >> st[i].math >> st[i].english;
        st[i].tot = st[i].chinese + st[i].math + st[i].english;
    }
    auto x = max_element(st, st + n, [](const student &x, const student &y) {
        return x.tot < y.tot;
    });
    cout << x->name << ' ' << x->chinese << ' ' <<  x->math << ' ' << x->english;
    return 0;
}