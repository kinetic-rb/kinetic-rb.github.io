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
class Writer {
  bool _SetP;
  char* buf;
  unsigned len, _precision, _Ppow;
  std::streambuf* outbuf;

 public:
  Writer(std::streambuf* _Out_Buf = std::cout.rdbuf(), unsigned Val = 33554432)
      : _SetP(false), _precision(3), _Ppow(1000), len(0) {
    outbuf = _Out_Buf;
    buf = new char[Val];
  }

  std::streambuf* rdbuf() { return outbuf; }
  void rdbuf(std::streambuf* _Out_Buf) {
    flush();
    outbuf = _Out_Buf;
  }

  void rdbuf(const char* File) {
    static std::ofstream out(File);
    outbuf = out.rdbuf();
  }

  void precision(unsigned pre) {
    _precision = pre;
    _SetP = true;
    unsigned pew = 1;
    for (unsigned x = 10; pre; pre >>= 1) {
      if (pre & 1) pew = pew * x;
      x = x * x;
    }
  }

  void flush() {
    outbuf->sputn(buf, len);
    len = 0;
  }

  template <typename Typex>
  Writer& operator<<(const Typex& x) {
    if (typeid(Typex) == typeid(short) || typeid(Typex) == typeid(int) ||
        typeid(Typex) == typeid(long) || typeid(Typex) == typeid(long long)) {
      if (x < 0) return *this << '-' << (~x + 1);
      if (x > 9) *this << x / 10;
      return *this << char(x % 10 ^ 48);
    }
    if (typeid(Typex) == typeid(unsigned short) ||
        typeid(Typex) == typeid(unsigned int) ||
        typeid(Typex) == typeid(unsigned long) ||
        typeid(Typex) == typeid(unsigned long long)) {
      if (x > 9) *this << x / 10;
      return *this << char(x % 10 ^ 48);
    }
  }
  Writer& operator<<(bool val) { return *this << (val ? '1' : '0'); }
  Writer& operator<<(char val) {
    buf[len++] = val;
    return *this;
  }
  Writer& operator<<(unsigned char val) {
    buf[len++] = val;
    return *this;
  }
  Writer& operator<<(float x) {
    if (x < 0) return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (unsigned i = 0; i < _precision; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (int i = _precision - 1; i && !_[i]; i--) Npre--;
      for (unsigned i = 0; i < Npre; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10) *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
  Writer& operator<<(double x) {
    if (x < 0) return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (unsigned i = 0; i < _precision; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (int i = _precision - 1; i && !_[i]; i--) Npre--;
      for (unsigned i = 0; i < Npre; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10) *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
  Writer& operator<<(long double x) {
    if (x < 0) return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (unsigned i = 0; i < _precision; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (unsigned i = 0; i < _precision; i++)
        _[i] = int(x * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(x * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(x + 1);
      }
      *this << '.';
      for (int i = _precision - 1; i && !_[i]; i--) Npre--;
      for (unsigned i = 0; i < Npre; i++) *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10) *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
} iw;

using namespace std;
using i16 = short;
using i32 = int;
using i64 = long long;
using ui16 = unsigned short;
using ui32 = unsigned int;
using ui64 = unsigned long long;

i64 gcd(i64 x, i64 y) { return y ? gcd(y, x % y) : x; }

i64 C_n_3(i64 n) { return (n * (n - 1) * (n - 2) / 3) >> 1; }

i32 main() {
#ifndef ONLINE_JUDGE
  ir.rdbuf("^");
#endif
  i64 n, m, res;
  ir >> n >> m;
  n++;
  m++;
  res = C_n_3(n * m) - C_n_3(n) * m - C_n_3(m) * n;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      res -= ((gcd(i, j) - 1) * (n - i) * (m - j)) << 1;
  iw << res;
  iw.flush();
  return 0;
}