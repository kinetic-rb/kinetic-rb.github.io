#include <iostream>
#include <array>

using namespace std;

array<array<char, 15>, 15> a, b, c;
signed n;

inline bool op1() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[j][n - i + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

inline bool op2() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[n - i + 1][n - j + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

inline bool op3() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[n - j + 1][i] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

inline bool op4() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            b[i][n - j + 1] = a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

inline bool op5() {
    op4();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
    if (op1())
        return true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
    if (op2())
        return true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
    if (op3())
        return true;
    return false;
}

inline bool op6() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    if (op1()) {
        cout << 1;
        return 0;
    }
    if (op2()) {
        cout << 2;
        return 0;
    }
    if (op3()) {
        cout << 3;
        return 0;
    }
    if (op4()) {
        cout << 4;
        return 0;
    }
    if (op5()) {
        cout << 5;
        return 0;
    }
    if (op6()) {
        cout << 6;
        return 0;
    }
    cout << 7;
    return 0;
}