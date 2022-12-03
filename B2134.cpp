#include <iostream>

using namespace std;

inline bool IP(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main() {
    int n, MAX = 0;
    cin >> n;
    for (int a = 2; a < n; a++)
        for (int b = 2; a + b <= n; b++)
            if (IP(a) && IP(b) && a + b == n)
                MAX = max(MAX, a * b);
    cout << MAX;
    return 0;
}