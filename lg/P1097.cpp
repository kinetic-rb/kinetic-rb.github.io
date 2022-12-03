#include <iostream>
#include <algorithm>

using namespace std;

int number[200000];

int main() {
    int n, last, now = 0;
    cin >> n;
    for(auto i = 0; i < n; i++) {
        cin >> number[i];
    }
    sort(number, number + n);
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