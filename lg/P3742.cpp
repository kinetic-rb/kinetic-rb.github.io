#include <iostream>

using namespace std;

int main() {
    int len;
    string x, z;
    cin >> len >> x >> z;
    for (int i = 0; i < len; i++) {
        if (x[i] < z[i]) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < len; i++) {
        (x[i] == z[i]) ? cout << 'z' : cout << z[i];
    }
    return 0;
}