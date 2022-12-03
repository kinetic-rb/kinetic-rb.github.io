#include <iostream>

using namespace std;

inline bool I7(int n) {
    while (n) {
        if (n % 10 == 7)
            return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (i % 7 && I7(i))
            sum += i * i;
    cout << sum;
    return 0;
}