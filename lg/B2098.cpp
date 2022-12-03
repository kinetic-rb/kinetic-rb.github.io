#include <iostream>
#include <map>

using namespace std;

map <int, bool> ac;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (!ac[t]) {
            cout << t << ' ';
            ac[t] = true;
        }
    }
    return 0;
}