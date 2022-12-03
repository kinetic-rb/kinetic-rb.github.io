#include <iostream>

using namespace std;

int main() {
    int s = 0, t;
    char c;
    for (cin >> t; cin >> c && c != '\n';) {
        int x;
        cin >> x;
        if (c == '*')
            t = t * x % 10000;
        else {
            s = (s + t) % 10000;
            t = x;
        }
    }
    cout << (s + t) % 10000;
    return 0;
}