#include <iostream>
#include "climits"

using namespace std;

int main() {
    int _, _1, _2, _3, _4, _5, _6, __ = INT_MAX, i, j, k;
    cin >> _ >> _1 >> _2 >> _3 >> _4 >> _5 >> _6;
    for(i = 0; i * _1 < _; i++);
    __ = min(__, i * _2);
    for(i = 0; i * _3 < _; i++);
    __ = min(__, i * _4);
    for(i = 0; i * _5 < _; i++);
    __ = min(__, i * _6);
    for(i = 0; i * _1 < _; i++) {
        for(j = 0; i * _1 + j * _3 < _; j++);
    }
    __ = min(__, i * _2 + j * _4);
    for(i = 0; i * _1 < _; i++) {
        for(j = 0; i * _1 + j * _5 < _; j++);
    }
    __ = min(__, i * _2 + j * _6);
    for(i = 0; i * _3 < _; i++) {
        for(j = 0; i * _4 + j * _6 < _; j++);
    }
    __ = min(__, i * _4 + j * _6);
    for(i = 0; _1 * i < _; i++) {
        for(j = 0; j * _3 + i * _1 < _; j++) {
            for(k = 0; k * _5 + j * _3 + i * _1 < _; k++);
        }
    }
    __ = min(__, i * _2 + j * _4 + k * _6);
    cout << __;
    return 0;
}