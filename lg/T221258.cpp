#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    unsigned int n;
    cin >> s >> n;
    cout << s[n % s.size() - 1];
    return 0;
}