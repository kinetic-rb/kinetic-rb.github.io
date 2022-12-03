#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, x, b, y;
    cin >> x >> a >> y >> b;
    printf("%.2f", double(b*y-a*x)/(b-a));
    return 0;
}