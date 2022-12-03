#include <iostream> // \u63d0\u4f9b cin \u548c cout
#include <algorithm> // \u63d0\u4f9b reverse \u51fd\u6570 \u548c max_element \u51fd\u6570
#include <string> // string \u7c7b
#include <cmath> // pow \u51fd\u6570
// \u6b64\u9898\u9700\u8981\u5f00 long long \u4e0d\u7136 90 \u5206

using namespace std;

inline string TO_Be(int B, long long n) {
    string num = "";
    for (; n; n /= B)
        num.push_back(n % B);
    reverse(num.begin(), num.end());
    for (auto& i : num) {
        (i >= 0 && i <= 9) ? i += '0' : i += 'A' - 10;
    }
    return num;
}

inline long long B_to(int B, string n) {
    long long num = 0;
    reverse(n.begin(), n.end());
    for (int i = 0; i < n.size(); i++) {
        if (n[i] >= '0' && n[i] <= '9')
            num += pow(B, i) * (n[i] - '0');
        else
            num += pow(B, i) * (n[i] - 'A' - 10);
    }
    return num;
}

inline int Min(string p, string q, string r) {
    char MIN = *max_element(p.begin(), p.end());
    MIN = max(MIN, *max_element(q.begin(), q.end()));
    MIN = max(MIN, *max_element(r.begin(), r.end()));
    return MIN - '0' + 1;
}

int main() {
    string q, p, r;
    cin >> p >> q >> r;
    for (int B = Min(p, q, r); B < 17; B++) {
        long long pmq = B_to(B, p) * B_to(B, q); // \u8ba1\u7b97 10 \u8fdb\u5236\u4e58\u79ef
        if (TO_Be(B, pmq) == r) { // \u628a\u8ba1\u7b97\u597d\u7684\u4e58\u79ef\u8f6c\u6362\u6210 B \u8fdb\u5236\uff0c\u7136\u540e\u5224\u7b49
            cout << B; // \u7b26\u5408\u6761\u4ef6\u5c31\u8f93\u51fa B
            return 0; // \u7ed3\u675f\u7a0b\u5e8f
        }
    }
    cout << 0; // \u5982\u679c\u6240\u6709\u8fdb\u5236\u90fd\u4e0d\u884c\uff0c\u6309\u7167\u9898\u76ee\u8981\u6c42\u8f93\u51fa 0
    return 0;
}