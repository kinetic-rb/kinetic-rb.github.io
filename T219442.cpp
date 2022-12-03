#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, sum = 1;
    cin >> n >> a >> b;
    for(int i = 0; i < b; i++)
        sum *= a;
    n /= sum;
    cout << n % a;
    return 0;
}