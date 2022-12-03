#include <iostream>

using namespace std;

register_t num[10000];
register_t cnt = 0;

int main() {
    register_t n;
    cin >> n;
    for(auto i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(auto j = 0; j < n; j++) {
        for(auto i = 1; i < n; i++) {
            if(num[i] < num[i - 1]) {
                swap(num[i], num[i - 1]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}