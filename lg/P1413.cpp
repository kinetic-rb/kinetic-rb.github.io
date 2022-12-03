#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct AC {
\tint p, t;
} z[2010];

int main()
{
\tint a[7], ans = 0, n;
\tcin >> n;
\tmemset(a, -60, sizeof(a));
\tfor (int i = 0; i < n; i++)
\t\tcin >> z[i].p >> z[i].t;
\tstable_sort(z, z + n, [](const AC& x, const AC& y) {
\t\treturn x.t < y.t;
\t});
\tfor (int i = 0; i < n; i++)
\t\tif (!(a[z[i].p] < z[i].t && a[z[i].p] + 60 >= z[i].t)) {
\t\t\tans++;
\t\t\ta[z[i].p] = z[i].t - 1;
\t\t}
\tcout << ans;
\treturn 0;
}