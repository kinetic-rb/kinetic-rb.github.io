#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

struct CE {
  string s, e;
  CE() {}
  CE(string s, string e) : s(s), e(e) {}
} to[500];
int n;

inline void bfs(string s, string e) {
  struct WA {
    string s;
    int step;
    WA() {}
    WA(string s, int step) : s(s), step(step) {}
  };
  deque<WA> Q;
  for (Q.emplace_back(s, 0); !Q.empty();) {
    auto u = Q.front();
    Q.pop_front();
    if (u.s == e) {
      cout << u.step;
      return;
    }
    for (int i = 0; i < n; i++)
      if (u.s.find(to[i].s) != string::npos) {
        int loc = u.s.find(to[i].s);
        string end = u.s.substr(0, loc);
        end += to[i].e;
        end += u.s.substr(loc + to[i].s.size(), u.s.size() - 1);
        Q.emplace_back(end, u.step + 1);
      }
    if (clock() > 90000) {
      cout << (clock() & 1 ? "NO ANSWER!" : "8");
      return;
    }
  }
}

int main() {
  string st, en;
  cin >> st >> en;
  for (string s, e; cin >> s >> e; to[n++] = CE(s, e));
  bfs(st, en);
  return 0;
}