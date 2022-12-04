#include <iostream>

using namespace std;

struct CE {
    int wt, ww, c;
} b[55];

int f[1001][1001];

int main() {
    int n, wtm, wwm;
    cin >> wtm >> wwm >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i].wt >> b[i].ww >> b[i].c;
    for (int i = 0; i < n; i++)
        for (int vt = wtm; vt >= b[i].wt; vt--)
            for (int vm = wwm; vm >= b[i].ww; vm--)
                f[vt][vm] = max(f[vt][vm], f[vt - b[i].wt][vm - b[i].ww] + b[i].c);
    cout << f[wtm][wwm];
    return 0;
}