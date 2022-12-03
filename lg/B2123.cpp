#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0, j; i < s.size(); cout << j - i << s[i], i = j)
        for (j = i + 1; s[i] == s[j]; j++);
    return 0;
}