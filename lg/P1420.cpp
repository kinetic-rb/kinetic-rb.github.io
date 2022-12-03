#include "iostream"

using namespace std;

int a[10000];

int main() {
    ios_base ::sync_with_stdio(false);
    int n, cnt = 0, MAX = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int L = 0; L < n; L++) {
        for(int R = L; R < n; R++) {
            cnt = 0;
            for(int i = L; i < R; i++) {
                if(a[i + 1] == a[i] + 1) {
                    cnt++;
                }
                    else {
                        break;
                    }
            }
            MAX = max(MAX, cnt);
        }
    }
    cout << ++MAX;
    return 0;
}