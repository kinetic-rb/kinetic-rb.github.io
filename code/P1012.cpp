#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[25];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    stable_sort(s, s + n, [](const string& a, const string& b) {
        return a + b > b + a;
    });
    for (int i = 0; i < n; i++)
        cout << s[i];
    return 0;
}