#include <iostream>
#include <iomanip>

using namespace std;

int n;
int pe[10];

bool ud[10];

void per(int x) {
    if(x == n + 1) {
        for(int i = 0; i < n; cout << setw(5) << pe[++i]);
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!ud[i]) {
            ud[i] = true;
            pe[x] = i;
            per(x + 1);
            ud[i] = false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin >> n;
    per(1);
    return 0;
}