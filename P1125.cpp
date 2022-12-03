#include <iostream>
#include <algorithm>

using namespace std;

int cnt[26];

inline bool IP(int x) {
\tif (x < 2)
\t\treturn false;
\tfor (int i = 2; i * i <= x; i++) {
\t\tif (!(x % i))
\t\t\treturn false;
\t}
\treturn true;
}

int main() {
\tfor (char ch; cin >> ch; cnt[ch - 'a']++);
\tstable_sort(cnt, cnt + 26);
\tfor (int i = 0; i < 26; i++) {
\t\tif (cnt[i] != 0) {
\t\t\tIP(cnt[25] - cnt[i]) ? cout << "Lucky Word
" << cnt[25] - cnt[i] : cout << "No Answer
0";
\t\t\treturn 0;
\t\t}
\t}
\treturn 0;
}