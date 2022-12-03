#include <iostream>
#include <algorithm>

using namespace std;

int l[25];
int n, Mal;
bool flag;

void maker(const int& idx, const int& l1, const int& l2, const int& l3, const int& l4) {
\tif (flag || l1 > Mal || l2 > Mal || l3 > Mal || l4 > Mal)
\t\treturn;
\tif (idx == n) {
\t\tif (l1 == l2 && l2 == l3 && l3 == l4 && l1)
\t\t\tflag = true;
\t\treturn;
\t}
\tmaker(idx + 1, l1 + l[idx], l2, l3, l4);
\tmaker(idx + 1, l1, l2 + l[idx], l3, l4);
\tmaker(idx + 1, l1, l2, l3 + l[idx], l4);
\tmaker(idx + 1, l1, l2, l3, l4 + l[idx]);
}

int main() {
\tint t;
\tfor (cin >> t; t--; flag = false) {
\t\tcin >> n;
\t\tMal = 0;
\t\tfor (int i = 0; i < n; i++) {
\t\t\tcin >> l[i];
\t\t\tMal += l[i];
\t\t}
\t\tstable_sort(l, l + n);
\t\treverse(l, l + n);
\t\tMal >>= 2;
\t\tmaker(0, 0, 0, 0, 0);
\t\tputs(flag ? "yes" : "no");
\t}
  return 0;
}