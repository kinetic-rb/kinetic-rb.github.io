#include <iostream>

using namespace std;

int f[101];
bool map[101];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char x;
        cin >> x;
        (x == 'X')? map[i] = true : map[i] = false;
    }
    f[0] = map[0];
    f[1] = map[1];
    f[2] = map[2];
    for(int i = 3; i < n; i++) {
        f[i] = min(min(f[i - 1], f[i - 2]), f[i - 3]) + map[i];
    }
    cout << f[n - 1] << endl;
    return 0;
}