#include <cstring>
#include <fstream>
#include <iostream>

namespace Fast_I {
char *_Buf, *_Start_ptr, *_End_ptr;
std::streambuf* inbuf;
unsigned int Size;

struct Fast_Istream {
  Fast_Istream(std::streambuf*, unsigned int);
  Fast_Istream(unsigned int);
  Fast_Istream& operator>>(char&);
  Fast_Istream& operator>>(char*);
  Fast_Istream& operator>>(bool&);
  Fast_Istream& operator>>(short&);
  Fast_Istream& operator>>(int&);
  Fast_Istream& operator>>(long&);
  Fast_Istream& operator>>(long long&);
  Fast_Istream& operator>>(unsigned short&);
  Fast_Istream& operator>>(unsigned int&);
  Fast_Istream& operator>>(unsigned long&);
  Fast_Istream& operator>>(unsigned long long&);
  Fast_Istream& operator>>(float&);
  Fast_Istream& operator>>(double&);
  Fast_Istream& operator>>(long double&);
  std::streambuf* rdbuf() { return inbuf; }
  void rdbuf(std::streambuf* _inbuf) { inbuf = _inbuf; }
  void rdbuf(const char*);
};
}  // namespace Fast_I
namespace Fast_O {
class Fast_Ostream {
  char* buf;
  unsigned int top;
  std::streambuf* outbuf;

  void Put_Int(long long);
  template <typename Typex>
  void Put_Unsigned(Typex);

 public:
  Fast_Ostream(std::streambuf*, unsigned int);
  Fast_Ostream(const char*, unsigned int);
  Fast_Ostream(unsigned int);
  void flush();
  ~Fast_Ostream();
  Fast_Ostream& operator<<(char);
  Fast_Ostream& operator<<(const char*);
  Fast_Ostream& operator<<(bool);
  Fast_Ostream& operator<<(short);
  Fast_Ostream& operator<<(int);
  Fast_Ostream& operator<<(long);
  Fast_Ostream& operator<<(long long);
  Fast_Ostream& operator<<(unsigned short);
  Fast_Ostream& operator<<(unsigned int);
  Fast_Ostream& operator<<(unsigned long);
  Fast_Ostream& operator<<(unsigned long long);
  std::streambuf* rdbuf() { return outbuf; }
  void rdbuf(std::streambuf* _outbuf) { outbuf = _outbuf; }
  void rdbuf(const char*);
};
}  // namespace Fast_O
namespace Fast_IO {
Fast_I ::Fast_Istream fin(std::cin.rdbuf(), 1048576);
Fast_O::Fast_Ostream fout(std::cout.rdbuf(), 16777216);
}  // namespace Fast_IO

#define cin Fast_IO::fin
#define cout Fast_IO::fout

/* ----------------Start---------------- */

using namespace std;
using tp = long long;
constexpr tp Hat_T = 1003, Hat_W = 33;

tp dp(tp, tp, tp);

tp t, w;
tp d[Hat_T], f[Hat_T][Hat_W];

signed main() {
  cin >> t >> w;
  for (tp i = 1; i <= t; ++i) {
    cin >> d[i];
  }
  cout << dp(1, 0, 1);
  return ~~0;
}

tp dp(tp x, tp dep, tp loc) {
  if (x > t) {
    return 0;
  }
  if (f[x][dep]) {
    return f[x][dep];
  }
  f[x][dep] = dp(x + 1, dep, loc);
  if (loc == d[x]) {
    ++f[x][dep];
  } else if (dep < w) {
    f[x][dep] = max(f[x][dep], dp(x + 1, dep + 1, d[x]) + 1);
  }
  return f[x][dep];
}

/* -----------------End----------------- */

namespace Fast_I {
Fast_Istream::Fast_Istream(std::streambuf* in, unsigned int Sz) {
  Fast_I::Size = Sz;
  inbuf = in;
  _Start_ptr = _End_ptr = _Buf = new char[Sz];
}
Fast_Istream::Fast_Istream(unsigned int Sz) {
  Fast_I::Size = Sz;
  _Start_ptr = _End_ptr = _Buf = new char[Sz];
}
void Fast_Istream::rdbuf(const char* File) {
  static ifstream __In__(File);
  rdbuf(__In__.rdbuf());
}
void Get_Char(char& _Val) {
  if (_Start_ptr == _End_ptr) {
    _Start_ptr = _Buf;
    _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
  }
  _Val = _Start_ptr == _End_ptr ? -1 : *_Start_ptr++;
}
Fast_Istream& Fast_Istream::operator>>(char& _Val) {
  Get_Char(_Val);
  while (_Val == 32 || _Val == 10 || _Val == 13 || _Val == 8 || _Val == 9 ||
         _Val == 7 || _Val == 12 || _Val == 11) {
    Get_Char(_Val);
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(char* _Val) {
  Get_Char(*_Val);
  while (*_Val == 32 || *_Val == 10 || *_Val == 13 || *_Val == 8 ||
         *_Val == 9 || *_Val == 7 || *_Val == 12 || *_Val == 11) {
    Get_Char(*_Val);
  }
  while (*_Val != 32 && *_Val != 10 && *_Val && *_Val != -1 && *_Val != 9 &&
         *_Val != 11 && *_Val != 12) {
    Get_Char(*++_Val);
  }
  *_Val = 0;
  return *this;
}
template <typename Typex>
void Get_Int(Typex& _Val) {
  char ch;
  bool f = false;
  for (Get_Char(ch); ch < 48 || ch > 57; Get_Char(ch)) {
    f = ch == 45;
  }
  for (_Val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    _Val = _Val * 10 + (ch ^ 48);
  }
  if (f) {
    _Val = ~_Val + 1;
  }
}
template <typename Typex>
void Get_Unsigned(Typex& _Val) {
  char ch;
  Get_Char(ch);
  while (ch < 48 || ch > 57) {
    Get_Char(ch);
  }
  for (_Val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    _Val = _Val * 10 + (ch ^ 48);
  }
}
template <typename Typex>
void Get_Double(Typex& _Val) {
  char ch;
  bool f = false;
  for (Get_Char(ch); ch < 48 || ch > 57; Get_Char(ch)) {
    f = ch == 45;
  }
  for (_Val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    _Val = _Val * 10 + (ch ^ 48);
  }
  if (ch == 46) {
    unsigned long long _Pow = 1;
    for (Get_Char(ch); ch > 47 && ch < 58; Get_Char(ch)) {
      _Val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
  }
  if (f) {
    _Val = -_Val;
  }
}
Fast_Istream& Fast_Istream::operator>>(bool& _Val) {
  char ch;
  Get_Char(ch);
  while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
         ch == 12 || ch == 11) {
    Get_Char(ch);
  }
  while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
         ch != 12) {
    _Val |= ch ^ 48;
    Get_Char(ch);
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(short& _Val) {
  Get_Int(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(int& _Val) {
  Get_Int(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long& _Val) {
  Get_Int(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long long& _Val) {
  Get_Int(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned short& _Val) {
  Get_Unsigned(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned int& _Val) {
  Get_Unsigned(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long& _Val) {
  Get_Unsigned(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long long& _Val) {
  Get_Unsigned(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(float& _Val) {
  Get_Double(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(double& _Val) {
  Get_Double(_Val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long double& _Val) {
  Get_Double(_Val);
  return *this;
}
}  // namespace Fast_I
namespace Fast_O {
Fast_Ostream::Fast_Ostream(std::streambuf* out, unsigned int Size) : top(0) {
  buf = (char*)malloc(Size);
  outbuf = out;
}
Fast_Ostream::Fast_Ostream(const char* File, unsigned int Size) : top(0) {
  buf = (char*)malloc(Size);
  rdbuf(File);
}
void Fast_Ostream::rdbuf(const char* File) {
  static ofstream __Out__(File);
  rdbuf(__Out__.rdbuf());
}
Fast_Ostream::Fast_Ostream(unsigned int Size) : top(0) {
  buf = (char*)malloc(Size);
}
void Fast_Ostream::flush() {
  outbuf->sputn(buf, top);
  top = 0;
}
Fast_Ostream::~Fast_Ostream() {
  flush();
  free(buf);
}
Fast_Ostream& Fast_Ostream::operator<<(char _Val) {
  buf[top++] = _Val;
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(const char* _Val) {
  while (*_Val) {
    buf[top++] = *_Val++;
  }
  return *this;
}
void Fast_Ostream::Put_Int(long long _Val) {
  if (_Val < 0) {
    operator<<('-');
    Put_Unsigned(~_Val + 1);
  } else {
    Put_Unsigned(_Val);
  }
}
template <typename Typex>
void Fast_Ostream::Put_Unsigned(Typex _Val) {
  char* _Stack = (char*)malloc(sizeof(Typex) * 3);
  unsigned S_top = 0;
  while (_Val) {
    _Stack[++S_top] = (_Val % 10) ^ 48;
    _Val /= 10;
  }
  if (!S_top) {
    operator<<('0');
  }
  while (S_top) {
    operator<<(_Stack[S_top--]);
  }
  free(_Stack);
}
Fast_Ostream& Fast_Ostream::operator<<(bool _Val) {
  operator<<(_Val ? '0' : '1');
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(short _Val) {
  Put_Int(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(int _Val) {
  Put_Int(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long _Val) {
  Put_Int(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long long _Val) {
  Put_Int(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned short _Val) {
  Put_Unsigned(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned int _Val) {
  Put_Unsigned(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long _Val) {
  Put_Unsigned(_Val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long long _Val) {
  Put_Unsigned(_Val);
  return *this;
}
}  // namespace Fast_O