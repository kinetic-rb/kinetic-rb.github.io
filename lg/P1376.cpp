#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c, y, S, l;
    long long N, ans = 0;
    cin >> N >> S;
    for(int i = 0; i < N; i++)
    {
        cin >> c >> y;
        if(!i)
            l = c;
                else
                    l = min(l + S, c);
        ans += l * y;
    }
    cout << ans;
    return 0;
}