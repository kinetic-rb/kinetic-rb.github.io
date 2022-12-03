#include <iostream>

using namespace std;

int num[1001];

int main() {
    int MAX = 0;
    for(int x; cin >> x && x != -1; num[x]++);
    for(int & i : num) {
        MAX = max(MAX, i);
    }
    for(int i = 0; i < 1001; i++) {
        if(num[i] == MAX) {
            cout << i;
            return 0;
        }
    }
    return 0;
}