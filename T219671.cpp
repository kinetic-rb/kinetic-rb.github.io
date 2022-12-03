#include<bits/stdc++.h>
using namespace std;
int main()
{
\tint x, s100, s20, s5;
\tcin >> x;
\ts100 = x / 100;
\tx %= 100;
\ts20 = x / 20;
\tx %= 20;
\ts5 = x / 5;
\tx %= 5;
\tcout << s100 << " " << s20 << " " << s5 << " " << x;
\treturn 0;
}