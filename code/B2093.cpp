#include <iostream>

using namespace std;

int num[10000];

int main() {
    int n, f;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> f;
    for(int i = 0; i < n; i++) {
        if(num[i] == f) {
            cout << i;
            exit(0);
        }
    }
    cout << -1;
    exit(0);
}