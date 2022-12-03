#include <bits/stdc++.h>

using namespace std;

int n, t;
int a[100001];

bool check(int x) {
    int l = 0;
    priority_queue <int, vector<int>, greater<int> > ac;
    for(int i = 1; i <= x; i++)
        ac.push(a[i]);
    if(l > t)
        return false;
    int z = x + 1, c = 0;
    for(int i = z; i <= n; i++) {
        l += ac.top() - c;
        c = ac.top();
        ac.pop();
        if(l > t)
            return false;
        ac.push(a[i] + c);
    }
    for(int i = 1; i <= x; i++){
        l += ac.top() - c;
        c = ac.top();
        ac.pop();
        if(l > t)
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid - 1;
                else
                    l = mid + 1;
    }
    cout << l;
    return 0;
}