#include <iostream>
#include <cstring>
#define L long

using namespace std;

struct Bigint {
  long size;
  long num[10000];
  Bigint() {
    size = 1;
    memset(num, 0, sizeof num);
  }
};

Bigint operator + (const Bigint& _x, const Bigint& _y) {
  Bigint _c;
  _c.size = max(_x.size, _y.size);
  for (register L i = 0; i < _c.size; i++) {
    _c.num[i] += _x.num[i] + _y.num[i];
    _c.num[i + 1] = _c.num[i] / 10;
    _c.num[i] %= 10;
  }
  for (; _c.num[_c.size]; _c.size++) {
    _c.num[_c.size + 1] = _c.num[_c.size] / 10;
    _c.num[_c.size] %= 10;
  }
  return _c;
}

inline bool operator < (const Bigint& x, const Bigint& y) {
  if (x.size != y.size) {
    return x.size < y.size;
  }
  for (register L i = x.size - 1; i > -1; i--) {
    if (x.num[i] != y.num[i]) {
      return x.num[i] < y.num[i];
    }
  }
  return false;
}

inline Bigint operator += (Bigint& x, const Bigint& y) {
    x = x + y;
    return x;
}

inline Bigint operator * (const Bigint& x, const Bigint& y) {
    Bigint z;
    z.size = x.size - 1 + y.size;
    for (register L i = 0; i < x.size; i++) {
        for (register L j = 0; j < y.size; j++) {
            z.num[i + j] += x.num[i] * y.num[j];
            z.num[i + j + 1] += z.num[i + j] / 10;
            z.num[i + j] %= 10;
        }
    }
    for (; z.num[z.size]; z.size++) {
        z.num[z.size + 1] = z.num[z.size] / 10;
        z.num[z.size] %= 10;
    }
    bool allzero = true;
    for (long i : x.num) {
        if (i && i != x.num[x.size]) {
            allzero = false;
            break;
        }
    }
    return z;
}

inline Bigint operator *= (Bigint& x, const Bigint& y) {
    x = x * y;
    return x;
}

inline void Cin(Bigint& x) {
    string X;
    cin >> X;
    x.size = X.size();
    for (register L i = 0; i < X.size(); i++)
        x.num[i] = X[x.size - i - 1] - '0';
}

inline void Cout(const Bigint& x) {
    for (register L i = x.size - 1; i > -1; i--)
        putchar(x.num[i] + '0');
}

int main() {
  Bigint sum, pew;
  Bigint n, i, one;
    one.num[0] = pew.num[0] = 1;
    Cin(n);
  for (i.num[0] = 1; i < n; i += one) {
    pew *= i;
    sum += pew;
  }
  Cout(sum + pew * n);
  return 0;
}