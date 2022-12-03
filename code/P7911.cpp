#include <iostream>

using namespace std;

bool HF(const string& x) {
  if (x[0] == '.' || *(x.end() - 1) == ':')
    return false;
  string format;
  int a, b, c, d, e, dc = 0, mc = 0;
  for (int i = 0; i < x.size(); i++)
    if (x[i] == '.')
      dc++;
    else if (x[i] == ':')
      mc++;
  if (dc != 3 || mc != 1)
    return false;
  for (int i = 1; i < x.size() - 1; i++)
    if (x[i] == '0' && x[i - 1] == '.' && (x[i + 1] != '.' && x[i + 1] != ':'))
      return false;
  for (int i = 1; i < x.size(); i++)
    if (x[i] >= '0' && x[i] <= '9' && x[i - 1] == '0' && (i == 1 || x[i - 2] == '.' || x[i - 2] == ':'))
      return false;
  if (x.find(".:") != string::npos || x.find("..") != string::npos || x.find(".", x.find(":")) != string::npos)
    return false;
  sscanf(x.c_str(), "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e);
  if (min(a, min(b, min(c, d))) < 0 || max(a, max(b, max(c, d))) > 255 || e < 0 || e > 65535)
    return false;
  return true;
}

struct SERVER {
  string P;
  int id;
} Server[1001];
int Server_cnt;

signed main() {
  int n;
  scanf("%d", &n);
  for (int k = 1; k <= n; k++) {
    string op, P;
    cin >> op >> P;
    if (!HF(P)) {
      puts("ERR");
      continue;
    }
    if (op == "Server") {
      bool f = true;
      for (int j = 0; j < Server_cnt; j++)
        if (Server[j].P == P) {
          f = false;
          puts("FAIL");
          break;
        }
      if (f) {
        Server[Server_cnt].P = P;
        Server[Server_cnt++].id = k;
        puts("OK");
      }
    } else {
      int f = -1;
      for (int j = 0; j < Server_cnt; j++)
        if (Server[j].P == P) {
          f = Server[j].id;
          break;
        }
      if (f != -1)
        printf("%d
", f);
      else
        puts("FAIL");
    }
  }
  return 0;
}
