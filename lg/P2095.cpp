#include<bits/stdc++.h>
using namespace std;
struct food
{
    int z, c;
}f[205];
bool cmp(food x, food y);
int main()
{
    int n, m, k, sum = 0, am = 0;
    int mk[105], amk[105];
    memset(amk, 0, sizeof(amk));
    cin >> n >> m >> k;
    for(int i = 0; i < k;cin >> mk[++i]);
    for(int i = 0; i < n; i++)
        cin >> f[i].z >> f[i].c;
    sort(f, f+n, cmp);
    for(int i = 0; i < n; i++)
    {
        if(am == m)
            break;
        if(mk[f[i].c] > amk[f[i].c])
        {
            sum += f[i].z;
            amk[f[i].c]++;
            am++;
        }
    }
    cout << sum;
    return 0;
}
bool cmp(food x, food y)
{
    return x.z > y.z;
}