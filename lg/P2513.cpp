#include <iostream>
#include <typeinfo>

using namespace std;

class Reader {
  char *_Buf, *_Strat_ptr, *_End_ptr;
  streambuf* inbuf;

 public:
  Reader(const unsigned& Val = 65536) {
    _End_ptr = _Strat_ptr = _Buf = new char[Val];
    inbuf = std::cin.rdbuf();
  }

  template <typename Typex>
  Reader& operator>>(Typex& val) {
    if (typeid(Typex) == typeid(char) ||
        typeid(Typex) == typeid(unsigned char)) {
      val = (_Strat_ptr == _End_ptr &&
                     (_End_ptr =
                          (_Strat_ptr = _Buf) + inbuf->sgetn(_Buf, sizeof _Buf),
                      _Strat_ptr == _End_ptr)
                 ? -1
                 : *_Strat_ptr++);
      return *this;
    }
    if (typeid(Typex) == typeid(short) || typeid(Typex) == typeid(int) ||
        typeid(Typex) == typeid(long) || typeid(Typex) == typeid(long long)) {
      char ch;
      bool f = false;
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
        f |= (ch == 45);
      for (val = 0; ch > 47 && ch < 58; *this >> ch)
        val = val * 10 + (ch ^ 48);
      if (f)
        val = ~val + 1;
      return *this;
    }
    if (typeid(Typex) == typeid(double) ||
        typeid(Typex) == typeid(long double) ||
        typeid(Typex) == typeid(float)) {
      char ch;
      bool f = false;
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
        f |= (ch == 45);
      for (val = 0; ch > 47 && ch < 58; *this >> ch)
        val = val * 10 + (ch ^ 48);
      if (ch == 46) {
        unsigned long long _Pow = 1;
        for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
          val += (ch ^ 48) * 1.0 / (_Pow *= 10);
      }
      if (f)
        val = -val;
      return *this;
    }
    if (typeid(Typex) == typeid(unsigned short) ||
        typeid(Typex) == typeid(unsigned int) ||
        typeid(Typex) == typeid(unsigned long) ||
        typeid(Typex) == typeid(unsigned long long)) {
      char ch;
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
        ;
      for (val = 0; ch > 47 && ch < 58; *this >> ch)
        val = val * 10 + (ch ^ 48);
      return *this;
    }
  }

  Reader& operator>>(char* val) {
    char ch, *ptr = val;
    for (*this >> ch; ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 ||
                      ch == 7 || ch == 12 || ch == 11;
         *this >> ch)
      ;
    for (; ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
           ch != 12;
         *this >> ch)
      *ptr++ = ch;
    *ptr = 0;
    return *this;
  }

  Reader& operator>>(string& val) {
    val.clear();
    char ch;
    for (*this >> ch; ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 ||
                      ch == 7 || ch == 12 || ch == 11;
         *this >> ch)
      ;
    for (; ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
           ch != 12;
         *this >> ch)
      val.push_back(ch);
    return *this;
  }
} ir;

int f[1005][1005];

int main() {
  int n, k;
  ir >> n >> k;
  f[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j <= k; j++) {
      (sum += f[i - 1][j]) %= 10000;
      f[i][j] = sum;
      if (j >= i - 1)
        sum = ((sum - f[i - 1][j - i + 1]) % 10000 + 10000) % 10000;
    }
  }
  cout << f[n][k];
  return 0;
}