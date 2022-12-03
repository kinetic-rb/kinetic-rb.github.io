#include <iostream>
#include <algorithm>

using namespace std;

int l[25];
int n, Mal;
bool flag;

void maker(const int& idx, const int& l1, const int& l2, const int& l3, const int& l4) {
  if (flag || l1 > Mal || l2 > Mal || l3 > Mal || l4 > Mal)
    return;
  if (idx == n) {
    if (l1 == l2 && l2 == l3 && l3 == l4 && l1)
      flag = true;
    return;
  }
  maker(idx + 1, l1 + l[idx], l2, l3, l4);
  maker(idx + 1, l1, l2 + l[idx], l3, l4);
  maker(idx + 1, l1, l2, l3 + l[idx], l4);
  maker(idx + 1, l1, l2, l3, l4 + l[idx]);
}

int main() {
  int t;
  for (cin >> t; t--; flag = false) {
    cin >> n;
    Mal = 0;
    for (int i = 0; i < n; i++) {
      cin >> l[i];
      Mal += l[i];
    }
    stable_sort(l, l + n);
    reverse(l, l + n);
    Mal >>= 2;
    maker(0, 0, 0, 0, 0);
    puts(flag ? "yes" : "no");
  }
  return 0;
}