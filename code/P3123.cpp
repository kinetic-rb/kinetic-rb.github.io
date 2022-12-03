#include <iostream>
#define fr(name) for (tp name(0); name ^ 7; ++name)

using namespace std;
using tp = int_fast64_t;

enum { B, E, S, I, G, O, M };

tp h[7][7];

signed main() {
  tp n, sum = 0;
  cin >> n;
  while (n--) {
    char c;
    tp x;
    cin >> c >> x;
    x %= 7;
    if (x < 0) {
        x += 7;
    }
    if (c == 'B') {
      ++h[B][x];
    }
    if (c == 'E') {
      ++h[E][x];
    }
    if (c == 'S') {
      ++h[S][x];
    }
    if (c == 'I') {
      ++h[I][x];
    }
    if (c == 'G') {
      ++h[G][x];
    }
    if (c == 'O') {
      ++h[O][x];
    }
    if (c == 'M') {
      ++h[M][x];
    }
  }
  fr(b) {
    if (h[B][b]) {
      fr(e) {
        if (h[E][e]) {
          fr(s) {
            if (h[S][s]) {
              fr(i) {
                if (h[I][i]) {
                  fr(g) {
                    if (h[G][g]) {
                      fr(o) {
                        if (h[O][o]) {
                          fr (m) {
                            if (h[M][m]) {
                              if (!((b + e + s + s + i + e) * (g + o + e + s) * (m + o + o) % 7)) {
                                sum += h[B][b] * h[E][e] * h[S][s] * h[I][i] * h[G][g] * h[O][o] * h[M][m];
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << sum;
  return 0;
}

/*
*/
