#include <iostream>
#include <string>

using namespace std;

string _2c(int x, int i = 0, string s = string("")) {
    if(!x)
        return string("0");
    do {
        if(x & 1)
            s = (i == 1 ? "2" : "2(" + _2c(i) + ")") + (s == "" ? "" : "+") + s;
    } while(++i, x >>= 1);
    return s;
}
int main() {
    int x;
    cin >> x;
    cout << _2c(x);
}