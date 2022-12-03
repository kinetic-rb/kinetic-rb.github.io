#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct CE {
\tint num[2][4];
\t
\tinline bool operator <(const CE &t) const {
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tif (num[i][j] != t.num[i][j])
\t\t\t\t\treturn num[i][j] < t.num[i][j];
\t\treturn 0;
\t}
\t
\tinline void A() {
\t\tint x[2][4];
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tx[i][j] = num[i][j];
\t\tfor (int i = 0; i < 4; i++)
\t\t\tnum[0][i] = x[1][i];
\t\tfor (int i = 0; i < 4; i++)
\t\t\tnum[1][i] = x[0][i];
\t}
\t
\tinline void B() {
\t\tswap(num[0][0], num[0][3]);
\t\tswap(num[1][0], num[1][3]);
\t\tswap(num[0][1], num[0][3]);
\t\tswap(num[1][1], num[1][3]);
\t\tswap(num[0][2], num[0][3]);
\t\tswap(num[1][2], num[1][3]);
\t}
\t
\tinline void C() {
\t\tint x[2][4];
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tx[i][j] = num[i][j];
\t\tnum[0][1] = x[1][1];
\t\tnum[0][2] = x[0][1];
\t\tnum[1][2] = x[0][2];
\t\tnum[1][1] = x[1][2];
\t}
\t
\tinline bool operator==(const CE& comp) const {
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tif (num[i][j] != comp.num[i][j])
\t\t\t\t\treturn false;
\t\treturn true;
\t}
} num, END;

set<CE> se;

inline void print(const pair<CE, string>& x) {
\tputs("QiPan :");
\tfor (int i = 0; i < 2; i++) {
\t\tfor (int j = 0; j < 4; j++)
\t\t\tcout << x.first.num[i][j] << ' ';
\t\tputs("");
\t}
\tputs("
operator:");
\tcout << x.second << '\n';
\tint t; cin>>t;
}

inline void bfs(const CE& start) {
\tqueue<pair<CE, string>> Q;
\tfunction<void(CE, string)> record  = [&](const CE& qp, string oper) -> void {
\t\tif (se.count(qp))
\t\t\treturn;
\t\tif (qp == END) {
\t\t\tcout << oper.size() << '\n' << oper;
\t\t\texit(0);
\t\t}
\t\tse.insert(qp);
\t\tQ.emplace(make_pair(qp, oper));
\t};
\tfor (record(start, ""); !Q.empty(); Q.pop()) {
\t\tCE x;
\t\t//print(Q.front());
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tx.num[i][j] = Q.front().first.num[i][j];
\t\tx.A();
\t\trecord(x, Q.front().second + 'A');
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tx.num[i][j] = Q.front().first.num[i][j];
\t\tx.B();
\t\trecord(x, Q.front().second + 'B');
\t\tfor (int i = 0; i < 2; i++)
\t\t\tfor (int j = 0; j < 4; j++)
\t\t\t\tx.num[i][j] = Q.front().first.num[i][j];
\t\tx.C();
\t\trecord(x, Q.front().second + 'C');
\t}
}

int main() {
\tfor (int i = 0; i < 4; i++)
\t\tnum.num[0][i] = i + 1;
\tfor (int i = 0; i < 4; i++)
\t\tnum.num[1][3 - i] = i + 5;
\t\t
    for (int j = 0; j < 4; j++) {
      char ch;
      cin >> ch;
      END.num[0][j] = ch ^ 48;
    }
    
    for (int j = 3; j >= 0; j--) {
      char ch;
      cin >> ch;
      END.num[1][j] = ch ^ 48;
    }
    
  bfs(num);
  return 0;
}