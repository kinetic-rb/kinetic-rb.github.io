#include <iostream>

using namespace std;

string output[5];

inline void op(int o) {
  if (o == 1) {
    output[0] += "..X.";
    output[1] += "..X.";
    output[2] += "..X.";
    output[3] += "..X.";
    output[4] += "..X.";
    return;
  }
  if (o == 2) {
    output[0] += "XXX.";
    output[1] += "..X.";
    output[2] += "XXX.";
    output[3] += "X...";
    output[4] += "XXX.";
    return;
  }
  if (o == 3) {
    output[0] += "XXX.";
    output[1] += "..X.";
    output[2] += "XXX.";
    output[3] += "..X.";
    output[4] += "XXX.";
    return;
  }
  if (o == 4) {
    output[0] += "X.X.";
    output[1] += "X.X.";
    output[2] += "XXX.";
    output[3] += "..X.";
    output[4] += "..X.";
    return;
  }
  if (o == 5) {
    output[0] += "XXX.";
    output[1] += "X...";
    output[2] += "XXX.";
    output[3] += "..X.";
    output[4] += "XXX.";
    return;
  }
  if (o == 6) {
    output[0] += "XXX.";
    output[1] += "X...";
    output[2] += "XXX.";
    output[3] += "X.X.";
    output[4] += "XXX.";
    return;
  }
  if (o == 7) {
    output[0] += "XXX.";
    output[1] += "..X.";
    output[2] += "..X.";
    output[3] += "..X.";
    output[4] += "..X.";
    return;
  }
  if (o == 8) {
    output[0] += "XXX.";
    output[1] += "X.X.";
    output[2] += "XXX.";
    output[3] += "X.X.";
    output[4] += "XXX.";
    return;
  }
  if (o == 9) {
    output[0] += "XXX.";
    output[1] += "X.X.";
    output[2] += "XXX.";
    output[3] += "..X.";
    output[4] += "XXX.";
    return;
  }
  output[0] += "XXX.";
  output[1] += "X.X.";
  output[2] += "X.X.";
  output[3] += "X.X.";
  output[4] += "XXX.";
}

int main() {
  int n;
  cin >> n;
  for (char c; cin >> c; op(c - 48));
  output[0].pop_back();
  output[1].pop_back();
  output[2].pop_back();
  output[3].pop_back();
  output[4].pop_back();
  cout << output[0] + '\n' + output[1] + '\n' + output[2] + '\n' + output[3] +
              '\n' + output[4] + '\n';
  return 0;
}