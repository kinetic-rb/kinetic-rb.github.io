#include <iostream>

using namespace std;

int main()
{
    long long n , x , _ = 0 , p;
    ios :: sync_with_stdio(0);
    cin >> n >> x >> p;
    for ( int i = 1 ; i < n ; i++ )
    {
        int t;
        cin >> t;
        if(t + p > x) {
            _ += t + p - x;
            t = x - p;
        }
        p = t;
    }
    cout << _;
    return 0;
}