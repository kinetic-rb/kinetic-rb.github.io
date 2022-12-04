#include <iostream>
#include <algorithm>
#define merger stable_sort

using namespace std;

int number[200000];

int main() {
    int n, last, now = 0;
    cin >> n;
    for(auto i = 0; i < n; i++) {
        cin >> number[i];
    }
    merger(number, number + n, [](int x, int y) {
        return x < y;
    });
    last = number[0];
    for(auto i = 1; i <= n; i++) {
        if(number[i] == last) {
            now++;
        } else {
            cout << last << " " << ++now << "\n";
            last = number[i];
            now = 0;
        }
    }
    return 0;
}