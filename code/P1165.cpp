#include <iostream>
#include <stack>

using namespace std;

stack <int> st;

int main() {
  int n;
  for (cin >> n; n--;) {
    int k, x;
    cin >> k;
    switch (k) {
      case 0 :
          cin >> x;
          st.push(st.empty() ? x : max(x, st.top()));
          break;
      case 1 :
          if (!st.empty())
            st.pop();
          break;
      default :
          cout << (st.empty() ? 0 : st.top()) << '\n';
    }
  }
  return 0;
}