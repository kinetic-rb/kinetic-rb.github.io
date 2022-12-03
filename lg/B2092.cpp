#include <iostream>

using namespace std;

bool light[5005];

int main() {
    register int n;
    bool flag = false;
    cin >> n;
    for (register int i = 2; i <= n; i++)
        for (register int j = i; j <= n; j += i)
            light[j] = !light[j];
    for (register int i = 1; i <= n; i++) {
        if (!light[i]) {
            if (!flag) {
                flag = true;
                cout << i;
            } else
                cout << ' ' << i;
        }
    }
}