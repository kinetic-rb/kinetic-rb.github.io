#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (((!(n % 4)) && n % 100) || (!(n % 400)))? 1 : 0;
    return 0;
}