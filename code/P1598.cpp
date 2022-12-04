#include <iostream>
#include <string>

using namespace std;

int num[26];

int main() {
    int maxn = 0;
    string str;
    for (int i = 0; i < 4; i++) {
        getline(cin, str);
        for (int j = 0; j < str.size(); j++) {
            if (isupper(str[j])) {
                num[str[j] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        maxn = max(maxn, num[i]);
    }
    for (int i = maxn; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            num[j] >= i ? j == 25 ? cout << '*' : cout << "* " : j == 25 ? cout << ' ' : cout << "	";
        }
        cout << '\n';
    }
    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'A') << " ";
    }
    return 0;
}