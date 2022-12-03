#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double n, x, y, c;
    cin >> n >> x >> y;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    c = n - ceil(y * 1.0 / x);
    if(c < 0)
        c = 0;
    cout << c;
    return 0;
}