#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map <char, bool> abc;

int main() {
    ios_base::sync_with_stdio(false);
    register short d;
    register string x;
    cin >> d >> x;
    for(auto i : x) {
        if(i >= 'A' && i <= 'Z')
            i += 32;
        abc[i] = true;
    }
    for(char i = 'a'; i <= 'z'; i++) {
        if(!abc[i]) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
    exit(0);
}