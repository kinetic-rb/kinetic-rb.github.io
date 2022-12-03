#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c, ans = INT_MAX;
    cin >> n >> a >> b >> c;
    for(int ag = 0; ag <= n / a; ag++)
    {
        for(int bg = 0; bg <= n / b; bg++)
        {
            for(int cg = 0; cg <= n / c; cg++)
            {
                if(ag * a + bg * b + cg * c == n)
                {
                    ans = min(ans, ag + bg + cg);
                }
            }
        }
    }
    cout << ans;
    return 0;
}