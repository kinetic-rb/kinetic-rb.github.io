#include <cstring>
#include <fstream>
#include <iostream>

template <typename Typex>
bool bin(Typex&);
template <typename Typex, typename... More>
bool bin(Typex&, More&...);
template <typename Typex>
void bout(const Typex&);
template <typename Typex, typename... More>
void bout(const Typex&, const More&...);

using namespace std;
using tp = uint_fast64_t;

string TO_Be(tp B, tp n) {
  string num = "";
  for (; n; n /= B) {
    num.push_back(n % B);
  }
  reverse(num.begin(), num.end());
  for (auto& i : num) {
    (i >= 0 && i <= 9) ? i += '0' : i += 'A' - 10;
  }
  return num;
}

signed main() {
  bout('{');
  for (tp x; bin(x);) {
    static bool first = 0;
    if (first) {
      bout(',');
    }
    tp cnt = 0;
    for (tp y(x); y; y /= 10) {
      ++cnt;
    }
    if (TO_Be(16, x).size() + 2 <= cnt) {
      bout("0x", TO_Be(16, x));
    } else {
      bout(x);
    }
    first = 1;
  }
  bout('}');
  return 0;
}

/***********************************************/

namespace Fast_I {
char *_Buf, *_Start_ptr, *_End_ptr;
std::streambuf* inbuf;
unsigned int Size;
bool _Ok;

struct Fast_Istream {
  Fast_Istream(std::streambuf* in, unsigned int Sz) {
    _Ok = 1;
    Fast_I::Size = Sz;
    inbuf = in;
    _Start_ptr = _End_ptr = _Buf = (char*)new char[Sz];
  }
  Fast_Istream(const char* in, unsigned int Sz) {
    _Ok = 1;
    Fast_I::Size = Sz;
    rdbuf(in);
    _Start_ptr = _End_ptr = _Buf = new char[Sz];
  }
  void rdbuf(const char* File) {
    static std::ifstream __In__(File);
    inbuf = __In__.rdbuf();
  }
};

void Get_Char(char& _Val) {
  if (_Start_ptr == _End_ptr) {
    _Start_ptr = _Buf;
    _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
  }
  if (_Start_ptr == _End_ptr) {
    _Val = -1;
    _Ok = 0;
  } else {
    _Val = *_Start_ptr++;
  }
}
void _Get(char& _Val) {
  if (_Ok) {
    Get_Char(_Val);
    while (_Val == 32 || _Val == 10 || _Val == 13 || _Val == 8 || _Val == 9 ||
           _Val == 7 || _Val == 12 || _Val == 11) {
      Get_Char(_Val);
    }
  }
}
void _Get(char* _Val) {
  if (_Ok) {
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
    --_Start_ptr;
  }
}
void _Get(std::string& _Val) {
  if (_Ok) {
    char c;
    Get_Char(c);
    while (c == 32 || c == 10 || c == 13 || c == 8 || c == 9 || c == 7 ||
           c == 12 || c == 11) {
      Get_Char(c);
    }
    for (_Val.clear();
         c != 32 && c != 10 && c && c != -1 && c != 9 && c != 11 && c != 12;
         Get_Char(c)) {
      _Val.push_back(c);
    }
    --_Start_ptr;
  }
}
template <typename Typex>
void Get_Int(Typex& _Val) {
  if (_Ok) {
    char ch;
    bool _F = false;
    for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
      _F = ch == 45;
    }
    for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      _Val = _Val * 10 + (ch ^ 48);
    }
    if (_F) {
      _Val = ~_Val + 1;
    }
    --_Start_ptr;
  }
}
template <typename Typex>
void Get_Unsigned(Typex& _Val) {
  if (_Ok) {
    char ch;
    Get_Char(ch);
    while ((ch < 48 || ch > 57) && ch != -1) {
      Get_Char(ch);
    }
    for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      _Val = _Val * 10 + (ch ^ 48);
    }
    --_Start_ptr;
  }
}
template <typename Typex>
void Get_Double(Typex& _Val) {
  if (_Ok) {
    char ch;
    bool _F = false;
    for (Get_Char(ch); (ch < 48 || ch > 57) && ch != -1; Get_Char(ch)) {
      _F = ch == 45;
    }
    for (_Val = 0; ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
      _Val = _Val * 10 + (ch ^ 48);
    }
    if (ch == 46) {
      unsigned long long _Pow = 1;
      for (Get_Char(ch); ch > 47 && ch < 58 && ch != -1; Get_Char(ch)) {
        _Val += Typex((ch ^ 48) * 1.0 / (_Pow *= 10));
      }
    }
    if (_F) {
      _Val = -_Val;
    }
    --_Start_ptr;
  }
}
void _Get(bool& _Val) {
  if (_Ok) {
    char ch;
    Get_Char(ch);
    while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
           ch == 12 || ch == 11) {
      Get_Char(ch);
    }
    while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
           ch != 12) {
      _Val |= ch != 48;
      Get_Char(ch);
    }
    --_Start_ptr;
  }
}
void _Get(short& _Val) {
  Get_Int(_Val);
}
void _Get(int& _Val) {
  Get_Int(_Val);
}
void _Get(long& _Val) {
  Get_Int(_Val);
}
void _Get(long long& _Val) {
  Get_Int(_Val);
}
void _Get(unsigned short& _Val) {
  Get_Unsigned(_Val);
}
void _Get(unsigned int& _Val) {
  Get_Unsigned(_Val);
}
void _Get(unsigned long& _Val) {
  Get_Unsigned(_Val);
}
void _Get(unsigned long long& _Val) {
  Get_Unsigned(_Val);
}
void _Get(float& _Val) {
  Get_Double(_Val);
}
void _Get(double& _Val) {
  Get_Double(_Val);
}
void _Get(long double& _Val) {
  Get_Double(_Val);
}
}  // namespace Fast_I
namespace Fast_O {
std::string buf;
std::streambuf* outbuf;

struct Fast_Ostream {
  Fast_Ostream(std::streambuf* out, unsigned int Size) {
    buf.reserve(Size);
    outbuf = out;
  }
  Fast_Ostream(std::streambuf* out) { outbuf = out; }
  Fast_Ostream(const char* File, unsigned int Size) {
    buf.reserve(Size);
    rdbuf(File);
  }
  Fast_Ostream(const char* File) { rdbuf(File); }
  void flush() {
    outbuf->sputn(buf.data(), buf.size());
    buf.clear();
  }
  ~Fast_Ostream() { flush(); }
  void rdbuf(const char* File) {
    static std::ofstream __Out__(File);
    outbuf = __Out__.rdbuf();
  }
};

void _Put(char _Val) {
  buf.push_back(_Val);
}
void _Put(const char* _Val) {
  while (*_Val) {
    buf.push_back(*_Val++);
  }
}
void _Put(const std::string& _Val) {
  for (auto&& i : _Val) {
    buf.push_back(i);
  }
}
template <typename Typex>
void Put_Unsigned(Typex _Val) {
  char* _Stack = (char*)malloc(sizeof(Typex) * 3);
  unsigned S_top = 0;
  while (_Val) {
    _Stack[++S_top] = (_Val % 10) ^ 48;
    _Val /= 10;
  }
  if (!S_top) {
    buf.push_back('0');
  }
  while (S_top) {
    buf.push_back(_Stack[S_top--]);
  }
  free(_Stack);
}
void Put_Int(long long _Val) {
  if (_Val < 0) {
    buf.push_back('-');
    Put_Unsigned(~_Val + 1);
  } else {
    Put_Unsigned(_Val);
  }
}
void _Put(bool _Val) {
  buf.push_back(_Val ? '1' : '0');
}
void _Put(short _Val) {
  Put_Int(_Val);
}
void _Put(int _Val) {
  Put_Int(_Val);
}
void _Put(long _Val) {
  Put_Int(_Val);
}
void _Put(long long _Val) {
  Put_Int(_Val);
}
void _Put(unsigned short _Val) {
  Put_Unsigned(_Val);
}
void _Put(unsigned int _Val) {
  Put_Unsigned(_Val);
}
void _Put(unsigned long _Val) {
  Put_Unsigned(_Val);
}
void _Put(unsigned long long _Val) {
  Put_Unsigned(_Val);
}
}  // namespace Fast_O

template <typename Typex>
bool bin(Typex& _Val) {
  Fast_I::_Get(_Val);
  return Fast_I::_Ok;
}

template <typename Typex, typename... More>
bool bin(Typex& _Val, More&... _More) {
  Fast_I::_Get(_Val);
  bin(_More...);
  return Fast_I::_Ok;
}

template <typename Typex>
void bout(const Typex& _Val) {
  Fast_O::_Put(_Val);
}

template <typename Typex, typename... More>
void bout(const Typex& _Val, const More&... _More) {
  Fast_O::_Put(_Val);
  bout(_More...);
}

namespace Fast_IO {
Fast_I::Fast_Istream fin(std::cin.rdbuf(), 1048576);
Fast_O::Fast_Ostream fout(std::cout.rdbuf());
}  // namespace Fast_IO