#include <iostream>
#include <set>

using namespace std;

set <string> xxxx;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        xxxx.insert(t);
    }
    cout << xxxx.size();
    exit(0);
}