#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    long long amc = 0, amz = 0;
    cin >> n >> m;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
        {
            if(x == y)
                amz += (n - x) * (m - y);
            if(x != y)
                amc += (n - x) * (m - y);
        }
    cout << amz << " " << amc;
    return 0;
}