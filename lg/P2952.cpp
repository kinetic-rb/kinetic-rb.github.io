#include <deque>
#include <iostream>
#define DEBUG 0

inline void FileSwitch(const char* InputFileName, const char* OutputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
#if DEBUG == 2
  freopen_s(&STREAM, OutputFileName, "w", stdout);
#endif
}

using namespace std;

int main() {
  FileSwitch("^", "#");
  deque<int> dq;
  int s;
  cin >> s;
  for (int i = 0; i < s; i++) {
    static int cow = 1;
    char a, b;
    cin >> a >> b;
    if (a == 'A')
      b == 'L' ? dq.push_front(cow++) : dq.push_back(cow++);
    else {
      int c;
      cin >> c;
      while (c--)
        b == 'L' ? dq.pop_front() : dq.pop_back();
    }
  }
  for (deque<int>::iterator i = dq.begin(); i != dq.end(); i++)
    cout << *i << '\n';
  return 0;
}