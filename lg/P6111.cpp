#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 5003;

template <typename Typex>
struct mvec {
\tstruct LNode {
\t\tLNode* next;
\t\tTypex val;
\t\t
\t\tLNode() = default;
\t} * head, *end;
\t
\tmvec() { head = end = nullptr; }
\t
\tvoid push_back(const Typex& v) {
\t\tif (head) {
\t\t\tLNode* t = new LNode;
\t\t\tt->val = v;
\t\t\tend->next = t;
\t\t\tend = t;
\t\t} else {
\t\t\thead = end = new LNode;
\t\t\thead->val = v;
\t\t}
\t}
};

struct Rs {
\ttp t, c;
\t
\tRs() = default;
\tRs(tp t, tp c) : t(t), c(c) {}
};

mvec<Rs> g[Hat_N];
bool vis[Hat_N];
tp k, cnt;

void dfs(tp x, tp r = 0x7fffffffffffffff) {
\tif (vis[x]) {
\t\treturn;
\t}
\tif (r >= k) {
\t\t++cnt;
\t}
\tvis[x] = 1;
\tfor (mvec<Rs>::LNode* it = g[x].head; it != g[x].end; it = it->next) {
\t\tdfs(it->val.t, min(r, it->val.c));
\t}
\tif (g[x].end) {
\t\tdfs(g[x].end->val.t, min(r, g[x].end->val.c));
\t}
}

signed main() {
\ttp n, q;
\tcin >> n >> q;
\tfor (tp i = 1; i < n; ++i) {
\t\ttp u, v, d;
\t\tcin >> u >> v >> d;
\t\tg[u].push_back(Rs(v, d));
\t\tg[v].push_back(Rs(u, d));
\t}
\twhile (q--) {
\t\ttp x;
\t\tcin >> k >> x;
\t\tcnt = -1;
\t\tmemset(vis, 0, sizeof vis);
\t\tdfs(x);
\t\tcout << cnt << '\n';
\t}
\treturn 0;
}