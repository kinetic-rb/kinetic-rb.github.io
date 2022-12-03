#include "iostream"

using namespace std;

long long n, f, num[1100000], TNode[1100000], flag[1100000];

void Build_Tree(long long at, long long l, long long r) {
  if (l == r) {
    TNode[at] = num[l];
    return;
  }
  Build_Tree(at << 1, l, (l + r) >> 1);
  Build_Tree(at << 1 | 1, ((l + r) >> 1) + 1, r);
  TNode[at] = TNode[at << 1] + TNode[at << 1 | 1];
}

inline void Add_Up(long long at, long long l, long long r, long long k) {
  flag[at] += k;
  TNode[at] += k * (r - l + 1);
}

void UpDate(const long long& Llimit,
            const long long& Rlimit,
            const long long& l,
            const long long& r,
            const long long& at,
            const long long& k) {
  if (l >= Llimit && r <= Rlimit) {
    Add_Up(at, l, r, k);
    return;
  }
  Add_Up(at << 1, l, (l + r) >> 1, flag[at]);
  Add_Up(at << 1 | 1, ((l + r) >> 1) + 1, r, flag[at]);
  flag[at] = 0;
  if (Llimit <= (l + r) >> 1)
    UpDate(Llimit, Rlimit, l, (l + r) >> 1, at << 1, k);
  if (Rlimit > (l + r) >> 1)
    UpDate(Llimit, Rlimit, ((l + r) >> 1) + 1, r, at << 1 | 1, k);
  TNode[at] = TNode[at << 1] + TNode[at << 1 | 1];
}

long long Ask(const long long& Llimit,
              const long long& Rlimit,
              const long long& l,
              const long long& r,
              const long long& at) {
  long long ans = 0;
  if (l >= Llimit && r <= Rlimit)
    return TNode[at];
  Add_Up(at << 1, l, (l + r) >> 1, flag[at]);
  Add_Up(at << 1 | 1, ((l + r) >> 1) + 1, r, flag[at]);
  flag[at] = 0;
  if (Llimit <= (l + r) >> 1)
    ans += Ask(Llimit, Rlimit, l, (l + r) >> 1, at << 1);
  if (Rlimit > (l + r) >> 1)
    ans += Ask(Llimit, Rlimit, ((l + r) >> 1) + 1, r, at << 1 | 1);
  return ans;
}

int main() {
  cin >> n >> f;
  for (long long i = 1; i <= n; i++)
    cin >> num[i];
  Build_Tree(1, 1, n);
  for (long long i = 1; i <= f; i++) {
    long long to, l, r, k;
    cin >> to;
    switch (to) {
      case 1:
        cin >> l >> r >> k;
        UpDate(l, r, 1, n, 1, k);
        break;
      case 2:
        cin >> k;
        UpDate(1, 1, 1, n, 1, k);
        break;
      case 3:
        cin >> k;
        UpDate(1, 1, 1, n, 1, -k);
        break;
      case 4:
        cin >> l >> r;
        cout << Ask(l, r, 1, n, 1) << '\n';
        break;
      default:
        cout << Ask(1, 1, 1, n, 1) << '\n';
    }
  }
  return 0;
}