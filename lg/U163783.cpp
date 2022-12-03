#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double n, x, y, c;
    cin >> n >> x >> y;
    c = n - ceil(y * 1.0 / x);
    if(c < 0)
        c = 0;
    cout << c;
    return 0;
}