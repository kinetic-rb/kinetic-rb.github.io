#include <iostream>

using namespace std;

int ap[2000000];

int main() {
    int n;
    cin >> n;
    for (int x; n--; ap[x]++)
        cin >> x;
    cin >> n;
    cout << ap[n];
    return 0;
}