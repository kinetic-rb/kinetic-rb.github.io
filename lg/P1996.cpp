#include <iostream>

using namespace std;

bool num[200];

int main() {
    int n, m, s = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(++s > n)
                s = 1;
            if(num[s])
                j--;
        }
        cout << s << ' ';
        num[s] = true;
    }
    return 0;
}
//3 6 9 2 7 1 8 5 10 4