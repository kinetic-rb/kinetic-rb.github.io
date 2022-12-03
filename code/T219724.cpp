#include<bits/stdc++.h>

using namespace std;
//5
//2 -1 2 -3 2
int main()
{
    int n, L = 0, R = 0, sum = 0, macs = INT_MIN;
    int a[1005];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(; L < n; L++)
    {
        for(sum = R = 0; R < n; R++)
        {
            for(int i = L; i <= R; i++)
                sum += a[i];
            macs = max(macs, sum);
            sum = 0;
        }
    }
    cout << macs;
    return 0;
}