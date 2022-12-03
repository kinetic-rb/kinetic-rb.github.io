#include <iostream>

using namespace std;

int main() {
    int c, t = 0, k;
    while (isdigit(c = getchar()))
        if (c == '3')
            t++;
    cin >> k;
    cout << (t == k ? "YES" : "NO");
    return 0;
}