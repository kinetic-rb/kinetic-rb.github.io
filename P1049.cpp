#include <iostream>
#include <typeinfo>
#include <functional>

using namespace std;

int num[35];
int v, n, MAX = -1e7;

int main() {
    ios_base::sync_with_stdio(false);
    int sum = 0;
    cin >> v >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    function<int(int)> so = [&so, &sum](int x) -> int {
        if(!(sum > v || x > n)) {
            MAX = max(MAX, sum);
            so(x + 1);
            int last = sum;
            sum += num[x];
            so(x + 1);
            sum = last;
        }
    };
    so(0);
    cout << v - MAX;
    return 0;
}