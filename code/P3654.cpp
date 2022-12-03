#include <iostream>
#include <array>

using namespace std;

array<array<char, 505>, 505> a;

int main() {
    int R, C, K, sum = 0;
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> a[i][j];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int n = 0;
            for (int k = j; k < j + K; k++) {
                if (a[i][k] == '.')
                    n++;
            }
            sum += (n == K);
        }
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            int n = 0;
            for (int k = j; k < j + K; k++) {
                if (a[k][i] == '.')
                    n++;
            }
            sum += (n == K);
        }
    }
    cout << sum / (1 + (K == 1));
    return 0;
}