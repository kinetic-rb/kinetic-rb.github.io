#include <fstream>
#include <iostream>
#include <vector>

namespace Fast_I {
char *_Buf, *_Start_ptr, *_End_ptr;
std::streambuf* inbuf;
unsigned int Size;
bool _Ok;

struct Fast_Istream {
  operator bool() { return _Ok; }
  Fast_Istream(std::streambuf*, unsigned int);
  Fast_Istream(unsigned int);
  Fast_Istream(const char*, unsigned int);
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
  Fast_Istream& operator>>(std::string&);
  template <typename Typex>
  void operator()(Typex& ___) {
    *this >> ___;
  }
  template <typename Typex, typename... More>
  void operator()(Typex&, More&...);
  std::streambuf* rdbuf() { return inbuf; }
  void rdbuf(std::streambuf* _inbuf) { inbuf = _inbuf; }
  void rdbuf(const char*);
  void pop();
  char peek();
};
}  // namespace Fast_I
namespace Fast_O {
std::vector<char> buf;
std::streambuf* outbuf;

struct Fast_Ostream {
  Fast_Ostream(std::streambuf*, unsigned int);
  Fast_Ostream(std::streambuf* out) { outbuf = out; }
  Fast_Ostream(const char*, unsigned int);
  Fast_Ostream(unsigned int);
  void flush();
  ~Fast_Ostream();
  void endl() { buf.push_back('\n'); }
  template <typename Typex>
  void endl(const Typex& ___);
  template <typename Typex, typename... More>
  void endl(const Typex&, const More&...);
  template <typename Typex>
  void operator()(const Typex& ___);
  template <typename Typex, typename... More>
  void operator()(const Typex&, const More&...);
  Fast_Ostream& operator<<(char);
  Fast_Ostream& operator<<(const char*);
  Fast_Ostream& operator<<(const std::string&);
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
Fast_I::Fast_Istream fin(std::cin.rdbuf(), 1048576);  // 1 MB
Fast_O::Fast_Ostream fout(std::cout.rdbuf());         // \u221e
}  // namespace Fast_IO

#define cin Fast_IO::fin
#define cout Fast_IO::fout

/* ------------------------------------- */

using namespace std;
using tp = long long;
constexpr tp Hat_N = 100003;

bool rec[Hat_N];
tp n;

tp lowbit(tp loc) {
  return loc & (~loc + 1);
}

void modify(tp loc) {
  while (loc <= n) {
    rec[loc] ^= 1;
    loc += lowbit(loc);
  }
}

bool query(tp loc) {
  bool sum = 0;
  while (loc) {
    sum ^= rec[loc];
    loc -= lowbit(loc);
  }
  return sum;
}

signed main() {
  tp m;
  cin(n, m);
  while (m--) {
    tp op;
    cin(op);
    if (op == 1) {
      tp l, r;
      cin(l, r);
      modify(l);
      modify(r + 1);
    } else {
      tp loc;
      cin(loc);
      cout.endl(query(loc));
    }
  }
  return 0;
}

/* ------------------------------------- */

namespace Fast_I {
Fast_Istream::Fast_Istream(std::streambuf* ___, unsigned int ____) {
  _Ok = 1;
  Fast_I::Size = ____;
  inbuf = ___;
  _Start_ptr = _End_ptr = _Buf = new char[____];
}
Fast_Istream::Fast_Istream(const char* ___, unsigned int ____) {
  _Ok = 1;
  Fast_I::Size = ____;
  rdbuf(___);
  _Start_ptr = _End_ptr = _Buf = new char[____];
}
Fast_Istream::Fast_Istream(unsigned int ___) {
  _Ok = 1;
  Fast_I::Size = ___;
  _Start_ptr = _End_ptr = _Buf = new char[___];
}
void Fast_Istream::rdbuf(const char* ___) {
  static std::ifstream __In__(___);
  rdbuf(__In__.rdbuf());
}
void Get_Char(char& ___) {
  if (_Start_ptr == _End_ptr) {
    _Start_ptr = _Buf;
    _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
  }
  if (_Start_ptr == _End_ptr) {
    ___ = -1;
    _Ok = 0;
  } else {
    ___ = *_Start_ptr++;
  }
}
Fast_Istream& Fast_Istream::operator>>(char& ___) {
  if (_Ok) {
    Get_Char(___);
    while (___ == 32 || ___ == 10 || ___ == 13 || ___ == 8 || ___ == 9 ||
           ___ == 7 || ___ == 12 || ___ == 11) {
      Get_Char(___);
    }
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(char* ___) {
  if (_Ok) {
    Get_Char(*___);
    while (*___ == 32 || *___ == 10 || *___ == 13 || *___ == 8 || *___ == 9 ||
           *___ == 7 || *___ == 12 || *___ == 11) {
      Get_Char(*___);
    }
    while (*___ != 32 && *___ != 10 && *___ && *___ != -1 && *___ != 9 &&
           *___ != 11 && *___ != 12) {
      Get_Char(*++___);
    }
    *___ = 0;
    --_Start_ptr;
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(std::string& ___) {
  if (_Ok) {
    char c;
    Get_Char(c);
    while (c == 32 || c == 10 || c == 13 || c == 8 || c == 9 || c == 7 ||
           c == 12 || c == 11) {
      Get_Char(c);
    }
    for (___.clear();
         c != 32 && c != 10 && c && c != -1 && c != 9 && c != 11 && c != 12;
         Get_Char(c)) {
      ___.push_back(c);
    }
    --_Start_ptr;
  }
  return *this;
}
template <typename Typex>
void Get_Int(Typex& ___) {
  if (_Ok) {
    char ch;
    bool _F = false;
    for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
      _F = ch == 45;
    }
    for (___ = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      ___ = ___ * 10 + (ch ^ 48);
    }
    if (_F) {
      ___ = ~___ + 1;
    }
    --_Start_ptr;
  }
}
template <typename Typex>
void Get_Unsigned(Typex& ___) {
  if (_Ok) {
    char ch;
    Get_Char(ch);
    while ((ch < 48 || ch > 57) && ch != -1) {
      Get_Char(ch);
    }
    for (___ = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      ___ = ___ * 10 + (ch ^ 48);
    }
    --_Start_ptr;
  }
}
template <typename Typex>
void Get_Double(Typex& ___) {
  if (_Ok) {
    char ch;
    bool _F = false;
    for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
      _F = ch == 45;
    }
    for (___ = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      ___ = ___ * 10 + (ch ^ 48);
    }
    if (ch == 46) {
      unsigned long long _Pow = 1;
      for (Get_Char(ch); ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
        ___ += Typex((ch ^ 48) * 1.0 / (_Pow *= 10));
      }
    }
    if (_F) {
      ___ = -___;
    }
    --_Start_ptr;
  }
}
Fast_Istream& Fast_Istream::operator>>(bool& ___) {
  if (_Ok) {
    char ch;
    Get_Char(ch);
    while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
           ch == 12 || ch == 11) {
      Get_Char(ch);
    }
    while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
           ch != 12) {
      ___ |= ch != 48;
      Get_Char(ch);
    }
    --_Start_ptr;
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(short& ___) {
  Get_Int(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(int& ___) {
  Get_Int(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long& ___) {
  Get_Int(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long long& ___) {
  Get_Int(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned short& ___) {
  Get_Unsigned(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned int& ___) {
  Get_Unsigned(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long& ___) {
  Get_Unsigned(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long long& ___) {
  Get_Unsigned(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(float& ___) {
  Get_Double(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(double& ___) {
  Get_Double(___);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long double& ___) {
  Get_Double(___);
  return *this;
}
template <typename Typex, typename... More>
void Fast_Istream::operator()(Typex& ___, More&... ____) {
  *this >> ___;
  operator()(____...);
}
void Fast_Istream::pop() {
  char ___;
  Get_Char(___);
}
char Fast_Istream::peek() {
  if (_Start_ptr == _End_ptr) {
    _Start_ptr = _Buf;
    _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
  }
  if (_Start_ptr == _End_ptr) {
    _Ok = 0;
    return -1;
  } else {
    return *_Start_ptr;
  }
}
}  // namespace Fast_I
namespace Fast_O {
Fast_Ostream::Fast_Ostream(std::streambuf* ___, unsigned int ____) {
  buf.reserve(____);
  outbuf = ___;
}
Fast_Ostream::Fast_Ostream(const char* ___, unsigned int ____) {
  buf.reserve(____);
  rdbuf(___);
}
void Fast_Ostream::rdbuf(const char* ___) {
  static std::ofstream __Out__(___);
  rdbuf(__Out__.rdbuf());
}
Fast_Ostream::Fast_Ostream(unsigned int ___) {
  buf.reserve(___);
}
void Fast_Ostream::flush() {
  outbuf->sputn(buf.data(), buf.size());
  buf.clear();
}
Fast_Ostream::~Fast_Ostream() {
  flush();
}
Fast_Ostream& Fast_Ostream::operator<<(char ___) {
  buf.push_back(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(const char* ___) {
  while (*___) {
    buf.push_back(*___++);
  }
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(const std::string& ___) {
  for (auto&& i : ___) {
    buf.push_back(i);
  }
  return *this;
}
template <typename Typex>
void Put_Unsigned(Typex ___) {
  char* ____ = (char*)malloc(sizeof(Typex) * 3);
  unsigned S_top = 0;
  while (___) {
    ____[++S_top] = (___ % 10) ^ 48;
    ___ /= 10;
  }
  if (!S_top) {
    buf.push_back('0');
  }
  while (S_top) {
    buf.push_back(____[S_top--]);
  }
  free(____);
}
void Put_Int(long long ___) {
  if (___ < 0) {
    buf.push_back('-');
    Put_Unsigned(~___ + 1);
  } else {
    Put_Unsigned(___);
  }
}
Fast_Ostream& Fast_Ostream::operator<<(bool ___) {
  buf.push_back(___ ? '1' : '0');
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(short ___) {
  Put_Int(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(int ___) {
  Put_Int(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long ___) {
  Put_Int(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long long ___) {
  Put_Int(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned short ___) {
  Put_Unsigned(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned int ___) {
  Put_Unsigned(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long ___) {
  Put_Unsigned(___);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long long ___) {
  Put_Unsigned(___);
  return *this;
}
template <typename Typex>
void Fast_Ostream::endl(const Typex& ___) {
  *this << ___ << '\n';
}
template <typename Typex, typename... More>
void Fast_Ostream::endl(const Typex& ___, const More&... ____) {
  *this << ___;
  endl(____...);
}
template <typename Typex>
void Fast_Ostream::operator()(const Typex& ___) {
  *this << ___;
}
template <typename Typex, typename... More>
void Fast_Ostream::operator()(const Typex& ___, const More&... ____) {
  *this << ___;
  operator()(____...);
}
}  // namespace Fast_O