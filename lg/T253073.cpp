#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(!(n % i))
            cnt++;
    }
    cout << cnt;
    exit(0);
}