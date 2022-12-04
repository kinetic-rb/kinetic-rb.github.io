#include "iostream"
#define exit   \
  cio.flush(); \
  return 0

using namespace std;

int num;

template <unsigned InBuf_Size = 1048576, unsigned OutBuf_Size = 33554433>
class _IOer_ {
  unsigned len, CFflush;
  char *_In_Buf, *_Out_Buf, *iS, *iT;

 public:
  _IOer_() : len(0) {
    _In_Buf = new char[InBuf_Size];
    _Out_Buf = new char[OutBuf_Size];
    iT = iS = 0;
    CFflush = OutBuf_Size / 16 * 15;
  }

  void flush() {
    num++;
    fwrite(_Out_Buf, 1, len, stdout);
    len = 0;
  }

  _IOer_& operator>>(char& Val) {
    Val = iS == iT
        ? iT = (iS = _In_Buf) + fread(_In_Buf, 1, sizeof _In_Buf, stdin),
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

  _IOer_& operator<<(_IOer_& Fls()) {
    flush();
    return *this;
  }

  _IOer_& operator<<(const char& ch) {
    _Out_Buf[len++] = ch;
    return *this;
  }

  template <typename Typex>
  _IOer_& operator<<(const Typex& x) {
    if (len > CFflush)
      flush();
    if (x < 0)
      return *this << '-' << -x;
    if (x > 9)
      *this << x / 10;
    return *this << char(x % 10 + 48);
  }
};

int main() {
    _IOer_ cio;
    int c, y, S;
    long long N, ans = 0;
    cio >> N >> S;
    for (int i = 0; i < N; i++) {
        cio >> c >> y;
        int l = (i ? min(l + S, c) : c);
        ans += l * y;
    }
    cio << ans;
    exit;
}