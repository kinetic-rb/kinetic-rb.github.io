#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct water{
\tint time, no;
} t[1005];

int main() {
\tdouble ans = 0;
\tint n, sum = 0;
\tcin >> n;
\tfor (int i = 0; i < n; t[i].no = ++i) {
\t\tcin >> t[i].time;
\t\tsum += t[i].time;
\t}
\tstable_sort(t, t + n, [](water x, water y) {
\t\t\treturn x.time < y.time;
\t});
\tfor (int i = 0; i < n; i++)
\t\tcout << t[i].no + 1 << " ";
\tfor (int i = 0; i < n; i++)
\t\tans += t[i].time * (n - i);
\tans -= sum;
\tcout << '\n' << fixed << setprecision(2) << ans / n;
\treturn 0;
}