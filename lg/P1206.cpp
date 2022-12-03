#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline int length(int s, int b) {
    int cnt = 0;
    while (s) {
        s /= b;
        cnt++;
    }
    return cnt;
}

int temp[30], xxx[30];

inline char To_true(int x) {
    switch (x) {
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        case 10 : return 'A';
        case 11 : return 'B';
        case 12 : return 'C';
        case 13 : return 'D';
        case 14 : return 'E';
        case 15 : return 'F';
        case 16 : return 'G';
        case 17 : return 'H';
        case 18 : return 'I';
        case 19 : return 'J';
        default : return 'K';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int b;
    cin >> b;
    for (int i = 1; i < 301; i++) {
        bool T = true;
        int pew = i * i, stop = length(pew, b);
        for (int j = 0; j < stop; j++) {
            temp[j] = pew / int(pow(b, j)) % b;
        }
        for (int j = 0; j < 30; j++)
            xxx[j] = temp[j];
        reverse(temp, temp + stop);
        for (int j = 0; j < 30; j++) {
            if (xxx[j] != temp[j]) {
                T = false;
                break;
            }
        }
        if (T) {
            int newstop = length(i, b);
            pew = i;
            for (int j = 0; j < newstop; j++) {
                xxx[j] = pew / int(pow(b, j)) % b;
            }
            for (int j = newstop - 1; j >= 0; j--) {
                cout << To_true(xxx[j]);
            }
            cout << ' ';
            for (int j = 0; j < stop; j++) {
                cout << To_true(temp[j]);
            }
            cout << "\n";
        }
    }
    return 0;
}