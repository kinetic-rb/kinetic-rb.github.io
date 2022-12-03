#include <iostream>
#include <algorithm>
#include <array>
#include <map>

using namespace std;

array<string, 100000> table;
array<int, 100000> money;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, all, pps;
    string name;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        table[i] = name;
    }
    while (cin >> name >> all >> pps) {
        if (!pps) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (table[j] == name) {
                money[j] += all % pps;
                money[j] -= all;
            }
        }
        for (int j = 0; j < pps; j++) {
            string Gname;
            cin >> Gname;
            for (int k = 0; k < n; k++) {
                if (table[k] == Gname) {
                    money[k] += all / pps;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << table[i] << ' ' << money[i] << '\n';
    }
    return 0;
}