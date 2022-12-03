#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, w[10001], ans, Lt[110];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= m; i++)
        Lt[i] = w[i];
    for(int i = m + 1; i <= n; i++)
    {
        int k = 1;
        for(int j = 1; j <= m; j++)
            if(Lt[j] < Lt[k])
                k = j;
        Lt[k] += w[i];
    }
    ans = Lt[1];
    for(int i = 1; i <= n; i++)
        ans = max(ans, Lt[i]);
    cout << ans;
    return 0;
}