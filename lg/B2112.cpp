#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string _1, _2;
        cin >> _1 >> _2;
        if(_1 == _2) {
            cout << "Tie
";
            continue;
        }
        cout << "Player";
        if(_1 == "Rock") {
            (_2 == "Scissors") ? cout << "1
" : cout << "2
";
            continue;
        }
        if(_1 == "Scissors") {
            (_2 == "Rock") ? cout << "2
" : cout << "1
";
            continue;
        }
        (_2 == "Rock") ? cout << "1
" : cout << "2
";
    }
    return 0;
}