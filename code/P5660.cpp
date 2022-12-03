#include <iostream>

using namespace std;

int main() {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        char t;
        cin >> t;
        if(t == '1')
            cnt++;
    }
    cout << cnt;
    return 0;
}