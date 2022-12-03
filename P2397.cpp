#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int as = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        if (as == m)
            cnt++;
        if (!cnt) {
            as = m;
            cnt++;
        }
        if (as != m) {
            cnt--;
        }
    }
    cout << as;
    return 0;
}