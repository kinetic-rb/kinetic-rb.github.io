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
  void Put_Unsigned(unsigned long long);

 public:
  Fast_Ostream(std::streambuf*, unsigned int);
  Fast_Ostream(const char*, unsigned int);
  Fast_Ostream(unsigned int);
  void flush();
  ~Fast_Ostream();
  Fast_Ostream& operator<<(char);
  Fast_Ostream& operator<<(const char*);
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
Fast_I ::Fast_Istream fin(std::cin.rdbuf(), 524288);
Fast_O::Fast_Ostream fout(std::cout.rdbuf(), 1048576);
}  // namespace Fast_IO

#define cin Fast_IO::fin
#define cout Fast_IO::fout
using namespace std;
using tp = long long;

tp gcd(tp, tp);

signed main() {
  tp n;
  cin >> n;
  while (n--) {
    tp a0, a1, b0, b1, cnt = 0;
    cin >> a0 >> a1 >> b0 >> b1;
    for (tp x = 1; x * x <= b1; ++x) {
      if (!(b1 % x)) {
        tp y = b1 / x;
        cnt +=
            (!(x % a1) && gcd(x / a1, a0 / a1) == 1 && gcd(b1 / b0, y) == 1) +
            (x ^ y && !(y % a1) && gcd(y / a1, a0 / a1) == 1 &&
             gcd(b1 / b0, b1 / y) == 1);
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}

tp gcd(tp x, tp y) {
  return y ? gcd(y, x % y) : x;
}

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
void Get_Char(char& val) {
  if (_Start_ptr == _End_ptr) {
    _Start_ptr = _Buf;
    _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
  }
  val = _Start_ptr == _End_ptr ? -1 : *_Start_ptr++;
}
Fast_Istream& Fast_Istream::operator>>(char& val) {
  Get_Char(val);
  while (val == 32 || val == 10 || val == 13 || val == 8 || val == 9 ||
         val == 7 || val == 12 || val == 11) {
    Get_Char(val);
  }
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(char* val) {
  Get_Char(*val);
  while (*val == 32 || *val == 10 || *val == 13 || *val == 8 || *val == 9 ||
         *val == 7 || *val == 12 || *val == 11) {
    Get_Char(*val);
  }
  while (*val != 32 && *val != 10 && *val && *val != -1 && *val != 9 &&
         *val != 11 && *val != 12) {
    Get_Char(*++val);
  }
  *val = 0;
  return *this;
}
template <typename Typex>
void Get_Int(Typex& val) {
  char ch;
  bool f = false;
  for (Get_Char(ch); ch < 48 || ch > 57; Get_Char(ch)) {
    f = ch == 45;
  }
  for (val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    val = val * 10 + (ch ^ 48);
  }
  if (f) {
    val = ~val + 1;
  }
}
template <typename Typex>
void Get_Unsigned(Typex& val) {
  char ch;
  Get_Char(ch);
  while (ch < 48 || ch > 57) {
    Get_Char(ch);
  }
  for (val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    val = val * 10 + (ch ^ 48);
  }
}
template <typename Typex>
void Get_Double(Typex& val) {
  char ch;
  bool f = false;
  for (Get_Char(ch); ch < 48 || ch > 57; Get_Char(ch)) {
    f = ch == 45;
  }
  for (val = 0; ch > 47 && ch < 58; Get_Char(ch)) {
    val = val * 10 + (ch ^ 48);
  }
  if (ch == 46) {
    unsigned long long _Pow = 1;
    for (Get_Char(ch); ch > 47 && ch < 58; Get_Char(ch)) {
      val += (ch ^ 48) * 1.0 / (_Pow *= 10);
    }
  }
  if (f) {
    val = -val;
  }
}
Fast_Istream& Fast_Istream::operator>>(short& val) {
  Get_Int(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(int& val) {
  Get_Int(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long& val) {
  Get_Int(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long long& val) {
  Get_Int(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned short& val) {
  Get_Unsigned(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned int& val) {
  Get_Unsigned(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long& val) {
  Get_Unsigned(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(unsigned long long& val) {
  Get_Unsigned(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(float& val) {
  Get_Double(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(double& val) {
  Get_Double(val);
  return *this;
}
Fast_Istream& Fast_Istream::operator>>(long double& val) {
  Get_Double(val);
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
Fast_Ostream& Fast_Ostream::operator<<(char val) {
  buf[top++] = val;
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(const char* val) {
  while (*val) {
    buf[top++] = *val++;
  }
  return *this;
}
void Fast_Ostream::Put_Int(long long val) {
  if (val < 0) {
    operator<<('-');
    Put_Unsigned(~val + 1);
  } else {
    Put_Unsigned(val);
  }
}
void Fast_Ostream::Put_Unsigned(unsigned long long val) {
  char* _Stack = (char*)malloc(21);
  unsigned S_top = 0;
  while (val) {
    _Stack[++S_top] = (val % 10) ^ 48;
    val /= 10;
  }
  if (!S_top) {
    operator<<('0');
  }
  while (S_top) {
    operator<<(_Stack[S_top--]);
  }
  free(_Stack);
}
Fast_Ostream& Fast_Ostream::operator<<(short val) {
  Put_Int(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(int val) {
  Put_Int(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long val) {
  Put_Int(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(long long val) {
  Put_Int(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned short val) {
  Put_Unsigned(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned int val) {
  Put_Unsigned(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long val) {
  Put_Unsigned(val);
  return *this;
}
Fast_Ostream& Fast_Ostream::operator<<(unsigned long long val) {
  Put_Unsigned(val);
  return *this;
}
}  // namespace Fast_O