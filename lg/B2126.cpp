#include <iostream>

using namespace std;

int main() {
    int k;
    pair<int, char> MAX = {0, 0};
    string s;
    cin >> k >> s;
    for (int i = 0, j; i < s.size(); i = j)
        for (j = i + 1; s[i] == s[j]; j++)
            if (j - i + 1 > MAX.first && MAX.first < k)
                MAX = make_pair(j - i + 1, s[i]);
    cout << (MAX.first >= k ? MAX.second : 'N') << (MAX.first >= k ? ' ' : 'o');
    return 0;
}