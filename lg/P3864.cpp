#include <iostream>
#include <map>
#define int long long

using namespace std;

map <char, int> Map;

signed main() {
    bool al = true;
    Map.insert(make_pair('A', 2));
    Map.insert(make_pair('B', 2));
    Map.insert(make_pair('C', 2));
    Map.insert(make_pair('D', 3));
    Map.insert(make_pair('E', 3));
    Map.insert(make_pair('F', 3));
    Map.insert(make_pair('G', 4));
    Map.insert(make_pair('H', 4));
    Map.insert(make_pair('I', 4));
    Map.insert(make_pair('J', 5));
    Map.insert(make_pair('K', 5));
    Map.insert(make_pair('L', 5));
    Map.insert(make_pair('M', 6));
    Map.insert(make_pair('N', 6));
    Map.insert(make_pair('O', 6));
    Map.insert(make_pair('P', 7));
    Map.insert(make_pair('R', 7));
    Map.insert(make_pair('S', 7));
    Map.insert(make_pair('T', 8));
    Map.insert(make_pair('U', 8));
    Map.insert(make_pair('V', 8));
    Map.insert(make_pair('W', 9));
    Map.insert(make_pair('X', 9));
    Map.insert(make_pair('Y', 9));
    int len, core, compare;
    cin >> core;
    for (int i = 0; i < 4617; i++) {
        compare = 0;
        string x;
        cin >> x;
        len = x.size();
        for (int j = 0; j < len; j++) {
            compare *= 10;
            compare += Map[x[j]];
        }
        if (core == compare) {
            al = false;
            cout << x << '\n';
        }
    }
    if (al) {
        cout << "NONE";
    }
    return 0;
}