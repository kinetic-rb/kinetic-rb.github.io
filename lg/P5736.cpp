#include <iostream>

using namespace std;

bool IP(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (!(x % i))
            return false;
    return x > 1;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (IP(x))
            cout << x << ' ';
    }
    return 0;
}