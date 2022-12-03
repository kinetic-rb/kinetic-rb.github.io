#include <iostream>
#include <functional>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    map<string, int> map_table;
    string temp, x;
    function<void (const int &, int)> dfs = [&](const int &l, int k) {
        if (k > l) {
            map_table[temp] = ++cnt;
            return;
        }
        for (char i = (char) (k == 1 ? 'a' : temp[k - 2] + 1); i <= 'z'; i++) {
            temp[k - 1] = i;
            dfs(l, k + 1);
        }
    };
    for (int len = 1; len < 7; len++) {
        temp.clear();
        temp.resize(len);
        dfs(len, 1);
    }
    cin >> x;
    cout << map_table[x];
    return 0;
}