#include <iostream>

using namespace std;

string s, s1;
double n, ans = 0;

int main() {
    cin >> n >> s >> s1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s1[i]) {
            ans++;
        }
    }
    (ans / s.size() >= n) ? cout << "yes" : cout << "no";
    return 0;
}