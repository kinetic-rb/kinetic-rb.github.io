#include "iostream"
#include "cmath"
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    if(n < 0)
    {
        n = abs(n);
        for(m = n % 10, n /= 10; n; n /= 10)
            m = m * 10 + n % 10;
        cout << "-" << m;
        return 0;
    }
    for(m = n % 10, n /= 10; n; n /= 10)
        m = m * 10 + n % 10;
    cout << m;
    return 0;
}