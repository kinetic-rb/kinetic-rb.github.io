#include "algorithm"
#include "iostream"

using namespace std;

int main() {
    int x, y;
    string a, b;
    cin >> a >> b;
    while (*(a.end() - 1) == 48 && a.size() > 1)
        a.pop_back();
    while (*(b.end() - 1) == 48 && b.size() > 1)
        b.pop_back();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    x = atoi(a.c_str());
    y = atoi(b.c_str());
    cout << max(x, y);
    return 0;
}