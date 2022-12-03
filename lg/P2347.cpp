#include <iostream>

using namespace std;

bool to[1000];

int main() {
    ios_base::sync_with_stdio(false);
    register int _1, _2, _3, _5, _10, _20, cnt = 0;
    cin >> _1 >> _2 >> _3 >> _5 >> _10 >> _20;
    for(register int _ = 0; _ <= _1; _++) {
        for(register int __ = 0; __ <= _2; __++) {
            for(register int ___ = 0; ___ <= _3; ___++) {
                for(register int ____ = 0; ____ <= _5; ____++) {
                    for(register int _____ = 0; _____ <= _10; _____++) {
                        for(register int ______ = 0; ______ <= _20; ______++) {
                            to[_ * 1 + __ * 2 + ___ * 3 + ____ * 5 + _____ * 10 + ______ * 20] = true;
                        }
                    }
                }
            }
        }
    }
    for(register int i = 1; i < 1002; i++) {
        if(to[i])
            cnt++;
    }
    cout << "Total=" << cnt;
    return 0;
}