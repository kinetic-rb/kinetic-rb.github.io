#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;

class Reader {
  char *_Buf, *_Strat_ptr, *_End_ptr;
  streambuf* inbuf;

 public:
  Reader(streambuf* _In_Buf = std::cin.rdbuf(), unsigned Val = 65536) {
    _End_ptr = _Strat_ptr = _Buf = new char[Val];
    inbuf = _In_Buf;
  }

  streambuf* rdbuf() { return inbuf; }
  void rdbuf(streambuf* _In_Buf) { inbuf = _In_Buf; }
  void rdbuf(const char* File) {
    static ifstream in(File);
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
      for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
        f |= (ch == 45);
      for (val = 0; ch > 47 && ch < 58; *this >> ch)
        val = val * 10 + (ch ^ 48);
      if (f)
        val = ~val + 1;
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
  Reader& operator>>(bool& val) {
    string x;
    *this >> x;
    val = x != "0";
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
      unsigned long long _Pow = 1;
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
      unsigned long long _Pow = 1;
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
      unsigned long long _Pow = 1;
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
class Writer {
  bool _SetP;
  char* buf;
  unsigned len, _precision, _Ppow;
  streambuf* outbuf;

 public:
  Writer(streambuf* _Out_Buf = std::cout.rdbuf(), unsigned Val = 1048576)
      : _SetP(false), _precision(3), _Ppow(1000) {
    outbuf = _Out_Buf;
    buf = new char[Val];
  }

  streambuf* rdbuf() { return outbuf; }
  void rdbuf(streambuf* _Out_Buf) {
    flush();
    outbuf = _Out_Buf;
  }
  void rdbuf(const char* File) {
    static ofstream out(File);
    outbuf = out.rdbuf();
  }
  void precision(unsigned pre) {
    _precision = pre;
    _SetP = true;
    unsigned pew = 1;
    for (unsigned x = 10; pre; pre >>= 1) {
      if (pre & 1)
        pew = pew * x;
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
      if (x < 0)
        return *this << '-' << (~x + 1);
      if (x > 9)
        *this << x / 10;
      return *this << char(x % 10 ^ 48);
    }
    if (typeid(Typex) == typeid(unsigned short) ||
        typeid(Typex) == typeid(unsigned int) ||
        typeid(Typex) == typeid(unsigned long) ||
        typeid(Typex) == typeid(unsigned long long)) {
      if (x > 9)
        *this << x / 10;
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
    if (x < 0)
      return *this << '-' << -x;
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
      for (unsigned i = 0; i < _precision; i++)
        *this << _[i];
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
      for (int i = _precision - 1; i && !_[i]; i--)
        Npre--;
      for (unsigned i = 0; i < Npre; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
  Writer& operator<<(double x) {
    if (x < 0)
      return *this << '-' << -x;
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
      for (unsigned i = 0; i < _precision; i++)
        *this << _[i];
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
      for (int i = _precision - 1; i && !_[i]; i--)
        Npre--;
      for (unsigned i = 0; i < Npre; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
  Writer& operator<<(long double x) {
    if (x < 0)
      return *this << '-' << -x;
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
      for (unsigned i = 0; i < _precision; i++)
        *this << _[i];
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
      for (int i = _precision - 1; i && !_[i]; i--)
        Npre--;
      for (unsigned i = 0; i < Npre; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    for (int y = _Ppow / 10; y; y /= 10)
      if (int(x * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(x * i) % 10 ^ 48);
        return *this << char(int(x * y) % 10 ^ 48);
      }
    return *this;
  }
} iw;

signed main() {
  int a, b;
  ir >> a >> b;
  iw << a + b;
  iw.flush();
  return 0;
}

///                               //\
///                               // |
///     ///////\   //////\        ///////\  //\   //\  //////\
///     //  __//\ //  __//\       //  __//\ // |  // |//  __//\
///     // |  // |// /  // |      // |  // |// |  // |// /  // |
///     // |  // |// |  // |      // |  // |// |  // |// |  // |
///     // |  // |\//////  |      ///////  |\//////  |\/////// |
///     \__|  \__| \______/       \_______/  \______/  \____// |
///                                                   //\   // |
///                                                   \//////  |
///                                                    \______/