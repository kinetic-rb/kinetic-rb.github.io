#include <iostream>
#include <bits/extc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  __gnu_pbds::tree<pair<long, long>, __gnu_pbds::null_type, std::greater<pair<long, long>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> rb;
  long n, m;
  cin >> n >> m;
  for (long i = 0; i < n; i++) {
    long x;
    cin >> x;
    rb.insert(make_pair(x, -i));
  }
  while (m--) {
    long op, x;
    cin >> op >> x;
    if (op == 1)
      cout << rb.find_by_order(x - 1)->first << '\n';
    else
      rb.insert(make_pair(x, m));
  }
  return 0;
}