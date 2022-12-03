#include <iostream>
#include <algorithm>

using namespace std;

register_t num[2000000];

int main() {
    register_t n, m;
    cin >> n >> m;
    for(auto i = 0; i < m; i++) {
        cin >> num[i];
    }
    sort(num, num + m);
    for(auto i = 0; i < m; i++) {
        cout << num[i] << ' ';
    }
    return 0;
}