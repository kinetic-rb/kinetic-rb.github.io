#include <iostream>
#include <array>

using namespace std;

array <long, 10000000> data;

int main() {
    int n, cnt = 0;
    for(cin >> n; n != 1; (n & 1) ? n = n * 3 + 1 : n /= 2)
        data[cnt++] = n;
    for(cout << "1 "; cnt--; cout << data[cnt] << ' ');
    return 0;
}