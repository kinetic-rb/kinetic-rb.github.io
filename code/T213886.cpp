#include <iostream>
#include <cstring>
#ifdef WIN64
#define L long
#else
#define L long long
#endif

using namespace std;

struct Bigint {
    L size;
    L num[1000000];
    Bigint() {
        size = 1;
        fill(num, num + 1000000, 0);
    }
};

Bigint operator + (const Bigint & _x, const Bigint & _y) {
    Bigint _c;
    _c.size = max(_x.size, _y.size);
    for(register L i = 0; i < _c.size; i++) {
        _c.num[i] += _x.num[i] + _y.num[i];
        _c.num[i + 1] = _c.num[i] / 10;
        _c.num[i] %= 10;
    }
    for(; _c.num[_c.size]; _c.size++) {
        _c.num[_c.size + 1] = _c.num[_c.size] / 10;
        _c.num[_c.size] %= 10;
    }
    return _c;
}

inline bool operator < (const Bigint & x, const Bigint & y) {
    if(x.size != y.size) {
        return x.size < y.size;
    }
    for(register L i = x.size - 1; i > -1; i--) {
        if(x.num[i] != y.num[i]) {
            return x.num[i] < y.num[i];
        }
    }
    return false;
}

inline Bigint operator += (Bigint & x, const Bigint & y) {
    x = x + y;
    return x;
}

Bigint operator - (Bigint x, const Bigint y) {
    for(register L i = 0; i < x.size; i++) {
        if(x.num[i] < y.num[i]) {
            x.num[i + 1]--;
            x.num[i] += 10;
        }
        x.num[i] -= y.num[i];
    }
    for(; !x.num[x.size - 1] && x.size > 1; x.size--);
    return x;
}

inline Bigint operator -= (Bigint & x, const Bigint & y) {
    x = x - y;
    return x;
}

inline Bigint operator * (const Bigint & x, const Bigint & y) {
    Bigint z;
    z.size = x.size - 1 + y.size;
    for(register L i = 0; i < x.size; i++) {
        for(register L j = 0; j < y.size; j++) {
            z.num[i + j] += x.num[i] * y.num[j];
            z.num[i + j + 1] += z.num[i + j] / 10;
            z.num[i + j] %= 10;
        }
    }
    for(; z.num[z.size]; z.size++) {
        z.num[z.size + 1] = z.num[z.size] / 10;
        z.num[z.size] %= 10;
    }
    return z;
}

inline Bigint operator *= (Bigint & x, const Bigint & y) {
    x = x * y;
    return x;
}

inline Bigint operator / (Bigint x, const Bigint & y) {
    Bigint z;
    z.size = x.size - y.size + 1;
    for(register L i  = x.size - 1; i > y.size - 2; i--) {
        x.num[i] += x.num[i + 1] * 10;
        x.num[i + 1] = 0;
        if(x.num[i]) {
            while(true) {
                bool geq = true;
                for(register L j = i, k = y.size - 1; k > -1; j--, k--) {
                    if(x.num[j] > y.num[k]) {
                        geq = true;
                        break;
                    }
                    if(x.num[j] < y.num[k]) {
                        geq = false;
                        break;
                    }
                }
                if(!geq)
                    break;
                z.num[i - y.size + 1]++;
                for(register L j = i - y.size + 1, k = 0; k < y.size; j++, k++) {
                    if(x.num[j] < y.num[k]) {
                        x.num[j + 1]--;
                        x.num[j] += 10;
                    }
                    x.num[j] -= y.num[k];
                }
            }
        }
    }
    for(; !z.num[z.size - 1] && z.size > 1; z.size--);
    return z;
}

inline Bigint operator /= (Bigint & x, const Bigint & y) {
    x = x / y;
    return x;
}

inline bool operator == (const Bigint & x, const Bigint & y) {
    if(x.size != y.size) {
        return false;
    }
    for(register L i = 0; i < x.size; i++) {
        if(x.num[i] != y.num[i]) {
            return false;
        }
    }
    return true;
}

inline void Cin(Bigint & x) {
    string X;
    cin >> X;
    x.size = X.size();
    for(register L i = 0; i < X.size(); i++)
        x.num[i] = X[x.size - i - 1] - '0';
}

inline void Cout(const Bigint & x) {
    for(register L i = x.size - 1; i > -1; i--)
        putchar(x.num[i] + '0');
}

int main() {
    Bigint a, b;
    Cin(a);
    Cin(b);
    if(b == a) {
        cout << 0;
        exit(0);
    }
    if(!(b < a)) {
        cout << "-";
        swap(a,b);
    }
    Cout(a - b);
    return 0;
}