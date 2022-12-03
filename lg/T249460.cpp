#include <iostream>

using namespace std;

int main() {
    int n, v, sum = 0, i;
    cin >> n >> v;
    for(i = 0; i < n && sum < v; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    if(sum < v) {
        cout << n;
        return 0;
    }
    cout << --i;
    return 0;
}