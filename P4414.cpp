#include <iostream>
#include <algorithm>
#define A x
#define B y
#define C z

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if(x > y)
        swap(x, y);
    if(y > z)
        swap(y, z);
    if(x > y)
        swap(x, y);
    char t;
    cin >> t;
    if(t == 'A')
        cout << A << ' ';
    if(t == 'B')
        cout << B << ' ';
    if(t == 'C')
        cout << C << ' ';
    cin >> t;
    if(t == 'A')
        cout << A << ' ';
    if(t == 'B')
        cout << B << ' ';
    if(t == 'C')
        cout << C << ' ';
    cin >> t;
    if(t == 'A')
        cout << A << ' ';
    if(t == 'B')
        cout << B << ' ';
    if(t == 'C')
        cout << C << ' ';
    return 0;
}