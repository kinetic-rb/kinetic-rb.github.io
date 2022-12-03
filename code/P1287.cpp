#include <fstream>
#include <iostream>
#include <typeinfo>

class Reader {
  char *_Buf, *_Strat_ptr, *_End_ptr;
  std::streambuf* inbuf;

 public:
  Reader(std::streambuf* _In_Buf = std::cin.rdbuf(), unsigned Val = 524288) {
    _End_ptr = _Strat_ptr = _Buf = new char[Val];
    inbuf = _In_Buf;
  }

  std::streambuf* rdbuf() { return inbuf; }

  void rdbuf(std::streambuf* _In_Buf) { inbuf = _In_Buf; }

  void rdbuf(const char* File) {
    static std::ifstream in(File);
    inbuf = in.rdbuf();
  }

  void _Set_Buf_Size(unsigned Val = 65536) { _Buf = new char[Val]; }

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
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
      for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
      if (f) val = ~val + 1;
      return *this;
    }
    if (typeid(Typex) == typeid(unsigned short) ||
        typeid(Typex) == typeid(unsigned int) ||
        typeid(Typex) == typeid(unsigned long) ||
        typeid(Typex) == typeid(unsigned long long)) {
      char ch;
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
        ;
      for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
      return *this;
    }
  }
  Reader& operator>>(bool& val) {
    std::string x;
    *this >> x;
    val = x != "0";
    return *this;
  }
  Reader& operator>>(double& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      unsigned long long _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
    if (f) val = -val;
    return *this;
  }
  Reader& operator>>(long double& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      unsigned long long _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
    if (f) val = -val;
    return *this;
  }
  Reader& operator>>(float& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      unsigned long long _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += float((ch ^ 48) * 1.0 / (_Pow *= 10));
    }
    if (f) val = -val;
    return *this;
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
  Reader& operator>>(std::string& val) {
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

using namespace std;
using i16 = short;
using i32 = int;
using i64 = long long;
using ui16 = unsigned short;
using ui32 = unsigned int;
using ui64 = unsigned long long;

i64 S[12][12] = {1};

i32 main() {
#ifndef ONLINE_JUDGE
  ir.rdbuf("^");
#endif
  i64 n, m, res;
  ir >> n >> m;
  for (i64 i = 1; i <= n; i++)
    for (i64 j = 1; j <= m; j++) S[i][j] = S[i - 1][j - 1] + S[i - 1][j] * j;
  res = S[n][m];
  for (i64 i = 2; i <= m; i++) res *= i;
  printf("%lld", res);
#ifndef ONLINE_JUDGE
  printf("
\33[32mclock : %d\33[0m", clock());
#endif
  return 0;
}