#include <bits/stdc++.h>
using namespace std;
int a, kkksc03, k1, k2, k3, k4, k5;
bool qwq, flag;
int main() {
    while (cin >> a && a != 0) {
        if (qwq)
            printf("\n");
        qwq = true;
        flag = false;
        for (int x1 = 0; x1 <= 9; x1++)
            for (int x2 = 0; x2 <= 9; x2++)
                for (int x3 = 0; x3 <= 9; x3++)
                    for (int x4 = 0; x4 <= 9; x4++)
                        for (int x5 = 0; x5 <= 9; x5++) {
                            if (x1 == x2 || x1 == x3 || x1 == x4 || x1 == x5 || x2 == x3 || x2 == x4 || x2 == x5 ||
                                x3 == x4 || x3 == x5 || x4 == x5)
                                continue;
                            kkksc03 = (x1 * 10000 + x2 * 1000 + x3 * 100 + x4 * 10 + x5) * a;
                            if (kkksc03 >= 100000)
                                break;
                            k1 = kkksc03 / 10000;
                            k2 = kkksc03 / 1000 % 10;
                            k3 = kkksc03 / 100 % 10;
                            k4 = kkksc03 / 10 % 10;
                            k5 = kkksc03 % 10;
                            if (k1 == k2 || k1 == k3 || k1 == k4 || k1 == k5 || k2 == k3 || k2 == k4 || k2 == k5 ||
                                k3 == k4 || k3 == k5 || k4 == k5)
                                continue;
                            if (k1 == x1 || k1 == x2 || k1 == x3 || k1 == x4 || k1 == x5 || k2 == x1 || k2 == x2 ||
                                k2 == x3 || k2 == x4 || k2 == x5 || k3 == x1 || k3 == x2 || k3 == x3 || k3 == x4 ||
                                k3 == x5 || k4 == x1 || k4 == x2 || k4 == x3 || k4 == x4 || k4 == x5 || k5 == x1 ||
                                k5 == x2 || k5 == x3 || k5 == x4 || k5 == x5)
                                continue;
                            flag = true;
                            cout << kkksc03 << " / " << x1 << x2 << x3 << x4 << x5 << " = " << a << endl;
                        }
        if (!flag)
            printf("There are no solutions for %d.
", a);
    }
}