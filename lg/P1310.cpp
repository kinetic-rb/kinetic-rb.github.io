#if false
#include <fstream>
std::ifstream cin("beta.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif

#include <stack>

using namespace std;

struct CE {
  int zero, one;
} ans[150005];

inline void mf(char ch, CE& a, CE& b) {
  if (ch == '+') {
    a.one = (a.one * (b.zero + b.one) + a.zero * b.one) % 10007;
    a.zero = a.zero * b.zero % 10007;
  } else {
    a.zero = (a.zero * (b.zero + b.one) + a.one * b.zero) % 10007;
    a.one = a.one * b.one % 10007;
  }
}

int main() {
  stack<char> s;
  string str;
  int len, t = 1;
  cin >> len >> str;
  str += ')';
  ans[1].zero = ans[1].one = 1;
  s.push('(');
  for (int i = 0; i <= len; i++)
    if (str[i] == '(')
      s.push('(');
    else if (str[i] == ')') {
      for (; s.top() != '('; s.pop(), t--)
        mf(s.top(), ans[t - 1], ans[t]);
      s.pop();
    } else {
      for (; s.top() <= str[i] && s.top() != '('; s.pop(), t--)
        mf(s.top(), ans[t - 1], ans[t]);
      s.push(str[i]);
      ans[++t].zero = 1;
      ans[t].one = 1;
    }
  cout << ans[1].zero;
  return 0;
}