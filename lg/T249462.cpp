#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    char x;
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << x;
        }
        cout << '\n';
    }
    exit(0);
}