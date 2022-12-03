#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char x[101], y[101];

int main() {
    cin >> x;
    for(int i = 0; i < strlen(x); i++)
        y[i] = x[i];
    reverse(y, y + strlen(y));
    for(int i = 0; i < strlen(y); i++) {
        if(y[i] != x[i]) {
            cout << "no";
            exit(0);
        }
    }
    cout << "yes";
    exit(0);
}