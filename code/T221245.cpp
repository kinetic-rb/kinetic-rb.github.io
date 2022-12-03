#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if(n == 1) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {// \u679a\u4e3e\u7ea6\u6570
        if(n % i == 0) {// i \u662f n \u7684\u7ea6\u6570
            return false;
        }
    }
    return true;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (is_prime(n) ? "Yes
" : "No
");
    }
    return 0;
}