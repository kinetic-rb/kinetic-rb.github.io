#include<iostream>

int main()
{
    long long x, n, sum = 1;
    std :: cin >> x >> n;
    for(int i = 0; i < n; i++)
        sum *= x + 1;
    std :: cout << sum;
    return 0;
}