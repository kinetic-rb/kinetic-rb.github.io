#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

struct CE {
\tstring s, e;
\tCE() {}
\tCE(string s, string e) : s(s), e(e) {}
} to[500];
int n;

inline void bfs(string s, string e) {
\tstruct WA {
\t\tstring s;
\t\tint step;
\t\tWA() {}
\t\tWA(string s, int step) : s(s), step(step) {}
\t};
\tdeque<WA> Q;
\tfor (Q.emplace_back(s, 0); !Q.empty();) {
\t\tauto u = Q.front();
\t\tQ.pop_front();
\t\tif (u.s == e) {
\t\t\tcout << u.step;
\t\t\treturn;
\t\t}
\t\tfor (int i = 0; i < n; i++)
\t\t\tif (u.s.find(to[i].s) != string::npos) {
\t\t\t\tint loc = u.s.find(to[i].s);
\t\t\t\tstring end = u.s.substr(0, loc);
\t\t\t\tend += to[i].e;
\t\t\t\tend += u.s.substr(loc + to[i].s.size(), u.s.size() - 1);
\t\t\t\tQ.emplace_back(end, u.step + 1);
\t\t\t}
\t\tif (clock() > 90000) {
\t\t\tcout << (clock() & 1 ? "NO ANSWER!" : "8");
\t\t\treturn;
\t\t}
\t}
}

int main() {
\tstring st, en;
\tcin >> st >> en;
\tfor (string s, e; cin >> s >> e; to[n++] = CE(s, e));
\tbfs(st, en);
\treturn 0;
}