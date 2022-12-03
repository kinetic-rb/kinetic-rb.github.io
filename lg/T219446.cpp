#include<bits/stdc++.h>
using namespace std;
int main()
{
\tint s, d, h, m;
\tcin >> s;
\td = s / 86400;
\ts %= 86400;
\th = s / 3600;
\ts %= 3600;
\tm = s / 60;
\ts %= 60;
\tcout << d << " " << h << " "<< m << " " << s;
\treturn 0;
}