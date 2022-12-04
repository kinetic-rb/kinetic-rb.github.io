#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 100003;

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
  Reader& operator>>(short& val) {
    char ch;
    bool f = false;
    for (*this >> ch; ch < 48 || ch > 57; *this >> ch) f |= (ch == 45);
    for (val = 0; ch > 47 && ch < 58; *this >> ch) val = val * 10 + (ch ^ 48);
    if (f) val = ~val + 1;
    return *this;
  }
  Reader& operator>>(int& val) {
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
  Reader& operator>>(long long& val) {
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

pair<vt, vt> num[Hat_N];

signed main() {
  vt n, ans = 0;
  ir >> n;
  for (vt i = 0; i < n; i++) {
    ir >> num[i].first;
    num[i].second = i;
  }
  stable_sort(num, num + n);
  for (vt j = 0; j < n; j++) {
    if (num[j].second - j > ans) {
      ans = num[j].second - j;
    }
  }
  cout << ans + 1;
  return 0;
}