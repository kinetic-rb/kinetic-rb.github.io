#include <iostream>

using namespace std;

int main() {
    bool last = false;
    int n, regist = 0;
    cin >> n;
    for (int x; cin >> x; last ? last = false : last = true)
        for (int i = 0; i < x; i++) {
            if (regist == n) {
                cout << '\n';
                regist = 0;
            }
            cout << last;
            regist++;
        }
    return 0;
}