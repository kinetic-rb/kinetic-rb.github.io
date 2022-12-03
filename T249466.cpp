#include <iostream>

using namespace std;

int num[10000];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(; n--; cout << num[n] << ' ');
    return 0;
}