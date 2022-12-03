#include<bits/stdc++.h>
using namespace std;
int main()
{
\tint x, a, b, c, t, y, j;
\tcin >> x >> a >> b >> c;
\tt = x / a;
\tx %= a;
\ty = t / b;
\tt %= b;
\tj = y / c;
\ty %= c;
\tcout << j << " " << y << " " << t << " " << x;
\treturn 0;
}