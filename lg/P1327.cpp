#include <algorithm>
#include <iostream>
#include <unordered_map>
#if !ONLINE_JUDGE
#pragma warning(disable : 4996)
#include <ctime>
#endif

inline void FileSwitch(const char* InputFileName,
                       const char* OutputFileName,
                       const bool& File) {
#if ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
#else
  freopen(InputFileName, "r", stdin);
  if (File)
    freopen(OutputFileName, "w", stdout);
#endif
}

using namespace std;

struct CE {
  int val, id;
  CE() {}
  CE(int val, int id) : val(val), id(id) {}

  inline bool operator<(const CE& comp) const { return val > comp.val; }
};

unordered_map<int, int> id;
int num[100005], h[100005];

signed main() {
  FileSwitch("^", "#", 0);
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    id[h[i] = num[i]] = i;
  }
  stable_sort(h, h + n);
  for (int i = 0; i < n; i++)
    if (num[i] != h[i]) {
      cnt++;
      id[num[i]] = id[h[i]];
      num[id[h[i]]] = num[i];
    }
  cout << cnt;
#if !ONLINE_JUDGE
  std::cout << "


Process Exited After " << clock() << " Ms";
#endif
  return 0;
}

//  8 23  4 16  77  -5  53  100
//  -5  23  4 16  77  8 53  100
//  -5  4 23  16  77  8 53  100
//  -5  4 8 16  77  23  53  100
//  -5  4 8 16  23  77  53  100
//  -5  4 8 16  23  53  77  100