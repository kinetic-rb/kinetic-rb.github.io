#include "iostream"
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

  inline unsigned _qpow(unsigned at, unsigned y) {
    unsigned pew;
    for (pew = 1; y; y >>= 1) {
      if (y & 1)
        pew = pew * at;
      at = at * at;
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
    long long at;
    *this >> at;
    Val = at;
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

  _IOer_& operator<<(const int& at) {
    if (len > CFflush)
      flush();
    if (at < 0)
      return *this << '-' << -at;
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const long& at) {
    if (len > CFflush)
      flush();
    if (at < 0)
      return *this << '-' << -at;
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const long long& at) {
    if (len > CFflush)
      flush();
    if (at < 0)
      return *this << '-' << -at;
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const short& at) {
    if (len > CFflush)
      flush();
    if (at < 0)
      return *this << '-' << -at;
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned& at) {
    if (len > CFflush)
      flush();
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned short& at) {
    if (len > CFflush)
      flush();
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned long& at) {
    if (len > CFflush)
      flush();
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const unsigned long long& at) {
    if (len > CFflush)
      flush();
    if (at > 9)
      *this << at / 10;
    return *this << char(at % 10 ^ 48);
  }

  _IOer_& operator<<(const double& at) {
    if (at < 0)
      return *this << '-' << -at;
    flush();
    *this << int(at);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
      }
      *this << '.';
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(at * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
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
      if (int(at * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(at * i) % 10 ^ 48);
        return *this << char(int(at * y) % 10 ^ 48);
      }
    return *this;
  }

  _IOer_& operator<<(const long double& at) {
    if (at < 0)
      return *this << '-' << -at;
    flush();
    *this << int(at);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
      }
      *this << '.';
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(at * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
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
      if (int(at * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(at * i) % 10 ^ 48);
        return *this << char(int(at * y) % 10 ^ 48);
      }
    return *this;
  }

  _IOer_& operator<<(const float& at) {
    if (at < 0)
      return *this << '-' << -at;
    flush();
    *this << int(at);
    if (_SetP) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
      }
      *this << '.';
      for (int i = 0; i < _precision; i++)
        *this << _[i];
      delete[] _;
      return *this;
    }
    if (int(at * _Ppow) % 10) {
      char* _ = new char[_precision];
      unsigned pew = 1, Npre = _precision;
      for (int i = 0; i < _precision; i++)
        _[i] = int(at * (pew *= 10)) % 10 ^ 48;
      _[_precision - 1] += (int(at * _Ppow * 10) % 10 > 4);
      for (int i = _precision - 1; _[i] == 58 && i; i--) {
        _[i] = 0;
        _[i - 1]++;
      }
      if (*_ == 58) {
        delete[] _;
        len = 0;
        return *this << unsigned(at + 1);
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
      if (int(at * y) % 10) {
        *this << '.';
        for (int i = 10; i < y; i *= 10)
          *this << char(int(at * i) % 10 ^ 48);
        return *this << char(int(at * y) % 10 ^ 48);
      }
    return *this;
  }
};

long long n, f, num[1100000], TNode[1100000], flag[1100000];

void Build_Tree(long long at, long long l, long long r) {
  if (l == r) {
    TNode[at] = num[l];
    return;
  }
  Build_Tree(at << 1, l, (l + r) >> 1);
  Build_Tree(at << 1 | 1, ((l + r) >> 1) + 1, r);
  TNode[at] = TNode[at << 1] + TNode[at << 1 | 1];
}

inline void Add_Up(long long at, long long l, long long r, long long k) {
  flag[at] += k;
  TNode[at] += k * (r - l + 1);
}

void UpDate(const long long& Llimit,
            const long long& Rlimit,
            const long long& l,
            const long long& r,
            const long long& at,
            const long long& k) {
  if (l >= Llimit && r <= Rlimit) {
    Add_Up(at, l, r, k);
    return;
  }
  Add_Up(at << 1, l, (l + r) >> 1, flag[at]);
  Add_Up(at << 1 | 1, ((l + r) >> 1) + 1, r, flag[at]);
  flag[at] = 0;
  if (Llimit <= (l + r) >> 1)
    UpDate(Llimit, Rlimit, l, (l + r) >> 1, at << 1, k);
  if (Rlimit > (l + r) >> 1)
    UpDate(Llimit, Rlimit, ((l + r) >> 1) + 1, r, at << 1 | 1, k);
  TNode[at] = TNode[at << 1] + TNode[at << 1 | 1];
}

long long Ask(const long long& Llimit,
              const long long& Rlimit,
              const long long& l,
              const long long& r,
              const long long& at) {
  long long ans = 0;
  if (l >= Llimit && r <= Rlimit)
    return TNode[at];
  Add_Up(at << 1, l, (l + r) >> 1, flag[at]);
  Add_Up(at << 1 | 1, ((l + r) >> 1) + 1, r, flag[at]);
  flag[at] = 0;
  if (Llimit <= (l + r) >> 1)
    ans += Ask(Llimit, Rlimit, l, (l + r) >> 1, at << 1);
  if (Rlimit > (l + r) >> 1)
    ans += Ask(Llimit, Rlimit, ((l + r) >> 1) + 1, r, at << 1 | 1);
  return ans;
}

int main() {
  cin >> n >> f;
  for (long long i = 1; i <= n; i++)
    cin >> num[i];
  Build_Tree(1, 1, n);
  for (long long i = 1; i <= f; i++) {
    long long to, l, r, k;
    cin >> to;
    switch (to) {
      case 1:
        cin >> l >> r >> k;
        UpDate(l, r, 1, n, 1, k);
        break;
      default:
        cin >> l >> r;
        cout << Ask(l, r, 1, n, 1) << '\n';
    }
  }
  return 0;
}