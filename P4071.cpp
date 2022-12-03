#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>

using i16 = short;
using i32 = int;
using i64 = long long;
using ui16 = unsigned short;
using ui32 = unsigned int;
using ui64 = unsigned long long;

class Reader {
  char *_Buf, *_Strat_ptr, *_End_ptr;
  std::streambuf* inbuf;

 public:
  Reader(std::streambuf* _In_Buf = std::cin.rdbuf(), ui32 Val = 524288) {
    _End_ptr = _Strat_ptr = _Buf = new char[Val];
    inbuf = _In_Buf;
  }

  std::streambuf* rdbuf() { return inbuf; }

  void rdbuf(std::streambuf* _In_Buf) { inbuf = _In_Buf; }

  void rdbuf(const char* File) {
    static std::ifstream in(File);
    inbuf = in.rdbuf();
  }

  void _Set_Buf_Size(ui32 Val = 65536) { _Buf = new char[Val]; }

  template <typename Typex>
  Reader& operator>>(Typex& val) {
    char ch;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      ;
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    return *this;
  }
  Reader& operator>>(bool& val) {
    std::string x;
    *this >> x;
    val = x != "0";
    return *this;
  }
  Reader& operator>>(char& val) {
    (_Strat_ptr == _End_ptr &&
     (_End_ptr = (_Strat_ptr = _Buf) + inbuf->sgetn(_Buf, sizeof _Buf)));
    val = _Strat_ptr == _End_ptr ? -1 : *_Strat_ptr++;
    return *this;
  }
  Reader& operator>>(unsigned char& val) {
    (_Strat_ptr == _End_ptr &&
     (_End_ptr = (_Strat_ptr = _Buf) + inbuf->sgetn(_Buf, sizeof _Buf)));
    val = *_Strat_ptr++;
    return *this;
  }
  Reader& operator>>(i16& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (f) val = ~val + 1;
    return *this;
  }
  Reader& operator>>(i32& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (f) val = ~val + 1;
    return *this;
  }
  Reader& operator>>(long& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (f) val = ~val + 1;
    return *this;
  }
  Reader& operator>>(i64& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (f) val = ~val + 1;
    return *this;
  }
  Reader& operator>>(double& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      ui64 _Pow = 1;
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
      ui64 _Pow = 1;
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
      ui64 _Pow = 1;
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

i64 qpow(i64 x, i64 y) {
  int pew;
  for (pew = 1; y; y >>= 1) {
    if (y & 1) pew = pew * x % 1000000007;
    x = x * x % 1000000007;
  }
  return pew;
}

i64 fact[1000005], inv[1000005], d[1000005];

i32 main() {
#ifndef ONLINE_JUDGE
  ir.rdbuf("^");
#endif
  i64 t;
  ir >> t;
  *fact = 1;
  for (int i = 1; i < 1000005; ++i) {
    fact[i] = fact[i - 1] * i % 1000000007;
    inv[i] = qpow(fact[i], 1000000005);
  }
  d[1] = 0;
  d[2] = 1;
  d[3] = 2;
  for (int i = 4; i < 1000005; ++i)
    d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % 1000000007;
  while (t--) {
    i64 n, m;
    ir >> n >> m;
    if (n - m == 1)
      printf("0
");
    else if (m == n)
      printf("1
");
    else if (!m)
      printf("%lld
", d[n]);
    else
      printf("%lld
", fact[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007 *
                           d[n - m] % 1000000007);
  }
#ifndef ONLINE_JUDGE
  printf("
clock : \33[32m%d\33[0m", clock());
#endif
  return 0;
}