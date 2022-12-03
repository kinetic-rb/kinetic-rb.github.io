#include<bits/stdc++.h>
using namespace std;
int a[5000005],k;
int findKth(const int k, int l, int r) {
    if (l == r) return a[l];
    int i = l, j = r, flag = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < flag) ++i;
        while (a[j] > flag) --j;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (k <= j) return findKth(k, l, j);
    else if (k >= i) return findKth(k, i, r);
    else return findKth(k, j + 1, i - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    register int n;
    cin>>n>>k;
    for(register int i=0;i<n;i++)
        cin>>a[i];
    cout<<findKth(k,0,n-1);
    return 0;
}