#include <iostream>
#include <map>

using namespace std;

long f[500005];
map<string, long> np;

long find(const long& u) {
  return (f[u] == u ? u : f[u] = find(f[u]));
}

long to_id(const string& name, long& id) {
  if (np.lower_bound(name)->first == name)
    id = np.lower_bound(name)->second;
  else {
    id = np.size();
    np.insert(make_pair(name, np.size()));
  }
}

string to_name(const long& id) {
  for (auto& i : np)
    if (i.second == id)
      return i.first;
}

signed main() {
  ios_base::sync_with_stdio(false);
  for (long i = 0; i < 500005; i++)
    f[i] = i;
  for (char c; cin >> c && c != '$';) {
    static long fa;
    if (c == '#') {
      long id;
      string name;
      cin >> name;
      to_id(name, id);
      fa = id;
    } else if (c == '+') {
      string name;
      long id;
      cin >> name;
      to_id(name, id);
      f[find(id)] = f[find(fa)];
    } else {
      long id;
      string name;
      cin >> name;
      to_id(name, id);
      cout << name << ' ' << to_name(find(id)) << '\n';
    }
  }
  return 0;
}