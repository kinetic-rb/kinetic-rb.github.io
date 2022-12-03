#include<iostream>
#include<queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    priority_queue <int> a;
    long long n, t, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push(-x);
    }
    for(int i = 1; i < n; i++)
    {
        ans -= a.top();
        t = a.top();
        a.pop();
        t += a.top();
        ans -= a.top();
        a.pop();
        a.push(t);
    }
    cout << ans;
    return 0;
}