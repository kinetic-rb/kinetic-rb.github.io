#include <iostream>
#include <map>
#include <bits/extc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  __gnu_pbds::tree<pair<long, pair<long, string>>, __gnu_pbds::null_type, std::greater<pair<long, pair<long, string>>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> rb;
  map<string, pair<long, long>> mx;
  long n;
  cin >> n;
  for (long i = 0; i < n; i++) {
    char op;
    cin >> op;
    if (op == '+') {
      string name;
      long mark;
      cin >> name >> mark;
      if (mx.count(name))
        rb.erase(rb.lower_bound(make_pair(mx[name].first, make_pair(mx[name].second, name))));
      rb.insert(make_pair(mark, make_pair(n - i, name)));
      mx[name] = make_pair(mark, n - i);
    } else {
        bool f = true;
        string name;
        cin >> name;
        for (const char& i : name)
          if (i < '0' || i > '9') {
            f = false;
            break;
          }
        if (f) {
          for (long d = atol(name.c_str()) - 1, cnt = 0; d < rb.size() && cnt < 10; cnt++, d++)
            cout << rb.find_by_order(d)->second.second << ' ';
          cout << '\n';
        } else
          cout << rb.order_of_key(make_pair(mx[name].first, make_pair(mx[name].second, name))) + 1 << '\n';
      }
  }
  return 0;
}