#include <fstream>
#include <iostream>

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
    for (val = 0; ch > 47 && ch < 58; *this >> ch)
      val = val * 10 + (ch ^ 48);
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
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch)
      val = val * 10 + (ch ^ 48);
    if (f)
      val = ~val + 1;
    return *this;
  }
  Reader& operator>>(i32& val) {
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
  Reader& operator>>(long& val) {
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
  Reader& operator>>(i64& val) {
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
  Reader& operator>>(double& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch)
      val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      ui64 _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
    if (f)
      val = -val;
    return *this;
  }
  Reader& operator>>(long double& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch)
      val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      ui64 _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
    if (f)
      val = -val;
    return *this;
  }
  Reader& operator>>(float& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch)
      val = val * 10 + (ch ^ 48);
    if (ch == 46) {
      ui64 _Pow = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        val += float((ch ^ 48) * 1.0 / (_Pow *= 10));
    }
    if (f)
      val = -val;
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

i64 f[1003];

i32 main() {
#ifndef ONLINE_JUDGE
  ir.rdbuf("#");
#endif
  i64 n, MAX = -0x7fffffff;
  ir >> n;
  for (i64 i = 1; i <= n; ++i) {
    i64 t;
    ir >> t;
    for (i64 j = i; j; --j)
      if (f[j - 1] + (t == j) > f[j])
        f[j] = f[j - 1] + (t == j);
  }
  for (i64 i = 0; i <= n; ++i)
    if (f[i] > MAX)
      MAX = f[i];
  printf("%lld", MAX);
#ifndef ONLINE_JUDGE
  int T__Time = clock() / 1000;
  printf("<
clock : ");
  if (T__Time < 200)
    printf("\33[32m");
  else if (T__Time < 300)
    printf("\33[34m");
  else if (T__Time < 500)
    printf("\33[33m");
  else if (T__Time < 1000)
    printf("\33[31m");
  else
    printf("\33[41m");
  printf("%d\33[0m", T__Time);
#endif
  return 0;
}
