#include <iostream>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

signed main() {
  ios_base::sync_with_stdio(false);
  static long num[200005];
  tree<pair<long, long>, null_type, less<pair<long, long>>, rb_tree_tag, tree_order_statistics_node_update> rb;
  long n, m, ptr = 0;
  cin >> n >> m;
  for (long i = 0; i < n; i++)
    cin >> num[i];
  for (long i = 0; i < m; i++) {
    long x;
    for (cin >> x; ptr < x; ptr++)
      rb.insert(make_pair(num[ptr], ptr));
    cout << rb.find_by_order(i)->first << '\n';
  }
  return 0;
}