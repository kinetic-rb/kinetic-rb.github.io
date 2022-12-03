#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    getline(cin, n);
    bool R = (n.find("\\r") != string::npos), N = (n.find("\
") != string::npos);
    if (R and N)
        cout << "windows";
    else if (R)
        cout << "mac";
    else
        cout << "linux";
    return 0;
}