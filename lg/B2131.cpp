#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    for (cin >> n; n--;) {
        string name;
        float t;
        bool kkk;
        cin >> name >> t >> kkk;
        if (kkk && t >= 37.5) {
            cout << name << '\n';
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}