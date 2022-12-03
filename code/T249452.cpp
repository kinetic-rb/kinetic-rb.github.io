#include <iostream>

using namespace std;

int main(){
    char a, b, c;
    cin >> a >> b >> c;
    cout << (a == b && b == c ? "yes" : "no") << endl;
    return 0;
}