#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int num[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    stable_sort(num, num + n);
    reverse(num, num + n);
    unique(num, num + n);
    cout << num[1] << '\n';
    return 0;
}