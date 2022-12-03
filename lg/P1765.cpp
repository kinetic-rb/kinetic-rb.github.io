#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int ans;
string a;

int ac[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
    getline(cin, a);
    for (auto i : a) {
        if (i >= 'a' && i <= 'z')
            ans += ac[i - 'a'];
        if (i == ' ')
            ans++;
    }
    printf("%d", ans);
    exit(0);
}