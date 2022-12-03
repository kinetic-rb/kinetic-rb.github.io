#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    reverse(num, num + n);
    cout << num[1];
    exit(0);
}