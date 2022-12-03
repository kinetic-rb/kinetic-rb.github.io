#include <iostream>

using namespace std;

long long n, a[1000000], m, p, s, k, sum, ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m >> p >> s >> k;
    for(int i = 1; i <= n; i++)
        sum += a[i] * (m - i);
    sum += s * (m - p);
    ans = m + int(sum * 1.0 / k + 0.5 * (sum > 0? 1 : -1));
    ans = max(min(ans, n), 1ll);
    cout << ans;
    return 0;
}