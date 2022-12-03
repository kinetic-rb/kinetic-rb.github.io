#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct CE {
  int num[2][4];
  
  inline bool operator <(const CE &t) const {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        if (num[i][j] != t.num[i][j])
          return num[i][j] < t.num[i][j];
    return 0;
  }
  
  inline void A() {
    int x[2][4];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        x[i][j] = num[i][j];
    for (int i = 0; i < 4; i++)
      num[0][i] = x[1][i];
    for (int i = 0; i < 4; i++)
      num[1][i] = x[0][i];
  }
  
  inline void B() {
    swap(num[0][0], num[0][3]);
    swap(num[1][0], num[1][3]);
    swap(num[0][1], num[0][3]);
    swap(num[1][1], num[1][3]);
    swap(num[0][2], num[0][3]);
    swap(num[1][2], num[1][3]);
  }
  
  inline void C() {
    int x[2][4];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        x[i][j] = num[i][j];
    num[0][1] = x[1][1];
    num[0][2] = x[0][1];
    num[1][2] = x[0][2];
    num[1][1] = x[1][2];
  }
  
  inline bool operator==(const CE& comp) const {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        if (num[i][j] != comp.num[i][j])
          return false;
    return true;
  }
} num, END;

set<CE> se;

inline void print(const pair<CE, string>& x) {
  puts("QiPan :");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++)
      cout << x.first.num[i][j] << ' ';
    puts("");
  }
  puts("
operator:");
  cout << x.second << '\n';
  int t; cin>>t;
}

inline void bfs(const CE& start) {
  queue<pair<CE, string>> Q;
  function<void(CE, string)> record  = [&](const CE& qp, string oper) -> void {
    if (se.count(qp))
      return;
    if (qp == END) {
      cout << oper.size() << '\n' << oper;
      exit(0);
    }
    se.insert(qp);
    Q.emplace(make_pair(qp, oper));
  };
  for (record(start, ""); !Q.empty(); Q.pop()) {
    CE x;
    //print(Q.front());
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        x.num[i][j] = Q.front().first.num[i][j];
    x.A();
    record(x, Q.front().second + 'A');
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        x.num[i][j] = Q.front().first.num[i][j];
    x.B();
    record(x, Q.front().second + 'B');
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 4; j++)
        x.num[i][j] = Q.front().first.num[i][j];
    x.C();
    record(x, Q.front().second + 'C');
  }
}

int main() {
  for (int i = 0; i < 4; i++)
    num.num[0][i] = i + 1;
  for (int i = 0; i < 4; i++)
    num.num[1][3 - i] = i + 5;
    
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