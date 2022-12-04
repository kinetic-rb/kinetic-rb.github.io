#include <iostream>
#include <array>
#define elif else if

using namespace std;

array <int, 995> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    register int n, MIN = 0x7fffffff;
    cin >> n;
    for(register int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(register int i = 0; i < 84; i++) {
        int c = 0, t = i + 17;
        for(register int j = 0; j < n; j++) {
            if(a[j] > t) {
                c += (a[j] - t) * (a[j] - t);
            } elif (a[j] < i) {
                c += (i - a[j]) * (i - a[j]);
            }
        }
        MIN = min(MIN, c);
    }
    cout << MIN;
    return 0;
}