#include <iostream>

using namespace std;

const int kMaxN = 2e5 + 1;

struct V {      // \u8282\u70b9
  char c;       // \u8fd0\u7b97\u7b26
  int a, l, r;  // \u6574\u6570\u3001\u5de6\u513f\u5b50\u7f16\u53f7\u3001\u53f3\u513f\u5b50\u7f16\u53f7
} v[kMaxN];

int s[kMaxN];  // \u8fd0\u7b97\u6808
int n, t;

void Tran(int i) {  // \u8f93\u51fa\u4ee5i\u53f7\u8282\u70b9\u4e3a\u6839\u7684\u5b50\u6811
  if (v[i].l) {     // \u662f\u8fd0\u7b97\u7b26
    cout << '(';
    Tran(v[i].l);  // \u8f93\u51fa\u5de6\u513f\u5b50
    cout << ' ' << v[i].c << ' ';
    Tran(v[i].r);  // \u8f93\u51fa\u53f3\u513f\u5b50
    cout << ')';
  } else {
    cout << v[i].a;  // \u8f93\u51fa\u6574\u6570
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].c;
    if (v[i].c >= '0' && v[i].c <= '9') {  // \u4e0b\u4e00\u4e2a\u662f\u6574\u6570
      cin.putback(v[i].c);                 // \u91cd\u8bfb
      cin >> v[i].a;
    } else { // \u4e0b\u4e00\u4e2a\u662f\u8fd0\u7b97\u7b26
      v[i].r = s[t--]; // \u8bb0\u5f55\u5de6\u53f3\u513f\u5b50
      v[i].l = s[t--];
    }
    s[++t] = i; // \u5c06\u65b0\u8282\u70b9\u5165\u6808
  }
  Tran(n);
  return 0;
}