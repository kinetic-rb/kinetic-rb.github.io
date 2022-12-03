#include "iostream"
#include "string"
#define exit   \
  cio.flush(); \
  return 0

using namespace std;

template <unsigned InBuf_Size = 1048576, unsigned OutBuf_Size = 33554432>
class _IOer_ {
  bool _SetP;
  unsigned len, CFflush, _precision, _Ppow;
  char *_In_Buf, *_Out_Buf, *iS, *iT;
  FILE *_InFILE, *_OutFILE;

  inline unsigned _qpow(unsigned x, unsigned y) {
    unsigned pew;
    for (pew = 1; y; y >>= 1) {
      if (y & 1)
        pew = pew * x;
      x = x * x;
    }
    return pew;
  }

 public:
  void SetIStreamFILE(FILE* _FILE_) { _InFILE = _FILE_; }

  void SetOStreamFILE(FILE* _FILE_) { _OutFILE = _FILE_; }

  void SetIStreamBufSize(const unsigned& _SIZE_) {
    _In_Buf = new char[InBuf_Size];
  }

  void SetOStreamBufSize(const unsigned& _SIZE_) {
    _Out_Buf = new char[OutBuf_Size];
  }

  void SetPrecision(const unsigned& precision) {
    _precision = precision;
    _Ppow = _qpow(10, _precision);
    _SetP = true;
  }

  _IOer_(FILE* IN_FILE = stdin, FILE* OUT_FILE = stdout)
      : len(0),
        CFflush(OutBuf_Size * 15 / 16),
        _precision(4),
        _Ppow(10000),
        _SetP(false) {
    SetIStreamFILE(IN_FILE);
    SetOStreamFILE(OUT_FILE);
    SetIStreamBufSize(InBuf_Size);
    SetOStreamBufSize(OutBuf_Size);
    iT = iS = 0;
  }

  void flush() {
    fwrite(_Out_Buf, 1, len, _OutFILE);
    len = 0;
  }

  _IOer_& operator>>(char& Val) {
    Val = iS == iT
        ? iT = (iS = _In_Buf) + fread(_In_Buf, 1, sizeof _In_Buf, _InFILE),
    (iS == iT ? -1 : *iS++) : *iS++;
    return *this;
  }

  template <typename Typex>
  _IOer_& operator>>(Typex& Val) {
    char ch;
    bool t = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      t |= ch == '-';
    for (Val = 0; ch > 47 && ch < 58; *this >> ch)
      Val = Val * 10 + (ch ^ 48);
    if (t)
      Val = -Val;
    return *this;
  }

  _IOer_& operator>>(bool& Val) {
    long long x;
    *this >> x;
    Val = x;
    return *this;
  }

  _IOer_& operator>>(double& Val) {
    char ch;
    bool t = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      t |= ch == '-';
    for (Val = 0; ch > 47 && ch < 58; *this >> ch)
      Val = Val * 10 + (ch ^ 48);
    if (ch == '.') {
      unsigned pew = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        Val += (ch ^ 48) * 1.0 / (pew *= 10);
    }
    if (t)
      Val = -Val;
    return *this;
  }

  _IOer_& operator>>(long double& Val) {
    char ch;
    bool t = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      t |= ch == '-';
    for (Val = 0; ch > 47 && ch < 58; *this >> ch)
      Val = Val * 10 + (ch ^ 48);
    if (ch == '.') {
      unsigned pew = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        Val += (ch ^ 48) * 1.0 / (pew *= 10);
    }
    if (t)
      Val = -Val;
    return *this;
  }

  _IOer_& operator>>(float& Val) {
    char ch;
    bool t = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch)
      t |= ch == '-';
    for (Val = 0; ch > 47 && ch < 58; *this >> ch)
      Val = Val * 10 + (ch ^ 48);
    if (ch == '.') {
      unsigned pew = 1;
      for (*this >> ch; ch > 47 && ch < 58; *this >> ch)
        Val += (ch ^ 48) * 1.0 / (pew *= 10);
    }
    if (t)
      Val = -Val;
    return *this;
  }

  _IOer_& operator<<(const char& ch) {
    _Out_Buf[len++] = ch;
    return *this;
  }

  _IOer_& operator<<(const unsigned char& ch) {
    _Out_Buf[len++] = ch;
    return *this;
  }

  _IOer_& operator<<(const int& x) {
    if (len > CFflush)
      flush();
    if (x < 0)
      return *this << '-' << -x;
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const long& x) {
    if (len > CFflush)
      flush();
    if (x < 0)
      return *this << '-' << -x;
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const long long& x) {
    if (len > CFflush)
      flush();
    if (x < 0)
      return *this << '-' << -x;
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const short& x) {
    if (len > CFflush)
      flush();
    if (x < 0)
      return *this << '-' << -x;
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned& x) {
    if (len > CFflush)
      flush();
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned short& x) {
    if (len > CFflush)
      flush();
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned long& x) {
    if (len > CFflush)
      flush();
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned long long& x) {
    if (len > CFflush)
      flush();
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 ^ 48);
  }

  _IOer_& operator<<(const double& x) {
    if (x < 0)
      return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < Npre; i++)
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

  _IOer_& operator<<(const long double& x) {
    if (x < 0)
      return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < Npre; i++)
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

  _IOer_& operator<<(const float& x) {
    if (x < 0)
      return *this << '-' << -x;
    flush();
    *this << int(x);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(x * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
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
      for (int i = 0; i < Npre; i++)
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
};

int g[100001];

int main() {
  _IOer_ cio;
  int l, q, cnt = 0, res = 0;
  for (cio >> l >> q; q--;) {
    bool op;
    int L, R;
    cio >> op >> L >> R;
    if (op) {
      for (int i = L; i <= R; i++)
        if (g[i] == 2)
          g[i] = 1;
    } else
      for (int i = L; i <= R; i++) {
        if (g[i] == 1)
          cnt++;
        g[i] = 2;
      }
  }
  for (int i = 0; i <= l; i++)
    if (g[i] == 1)
      res++;
  cio << res << '\n' << cnt;
  exit;
}