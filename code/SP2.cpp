#include <iostream>

using namespace std;

inline bool IP(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (!(x % i))
            return false;
    return true;
}

int main() {
    int t;
    for (cin >> t; t--; cout << '\n') {
        int srx, sry;
        cin >> srx >> sry;
        for (int j = srx; j <= sry; j++)
            if (IP(j))
                printf("%d
", j);
    }
    return 0;
}