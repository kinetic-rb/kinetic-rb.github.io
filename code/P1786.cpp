#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct AC {
    string na, zw, xzw;
    long long bg;
    int le, h;
} ab[115];

int change(string a) {
    if (a == "BangZhu")
        return 0;
    if (a == "FuBangZhu")
        return 1;
    if (a == "HuFa")
        return 2;
    if (a == "ZhangLao")
        return 3;
    if (a == "TangZhu")
        return 4;
    if (a == "JingYing")
        return 5;
    if (a == "BangZhong")
        return 6;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ab[i].na >> ab[i].zw >> ab[i].bg >> ab[i].le;
        ab[i].h = i;
    }
    stable_sort(ab + 4, ab + 1 + n, [](const AC & x, const AC & y) {
        return (x.bg == y.bg ? x.h < y.h : x.bg > y.bg);
    });
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            ab[i].xzw = "BangZhu";
        else if (i == 2 || i == 3)
            ab[i].xzw = "FuBangZhu";
        else if (i == 4 || i == 5)
            ab[i].xzw = "HuFa";
        else if (i >= 6 && i <= 9)
            ab[i].xzw = "ZhangLao";
        else if (i > 9 && i < 17)
            ab[i].xzw = "TangZhu";
        else if (i > 16 && i < 42)
            ab[i].xzw = "JingYing";
        else ab[i].xzw = "BangZhong";
    }
    stable_sort(ab + 1, ab + 1 + n, [](const AC & x, const AC & y) {
        if (change(x.xzw) != change(y.xzw)) {
            return change(x.xzw) < change(y.xzw);
        }
        return ((x.le == y.le) ? x.h < y.h : x.le > y.le);
    });
    for (int i = 1; i <= n; i++) {
        cout << ab[i].na << " " << ab[i].xzw << " " << ab[i].le << endl;
    }
    return 0;
}