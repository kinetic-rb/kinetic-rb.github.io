#include <iostream>

using namespace std;

int num[1001], f[1001];

int find(int x) {
    int sum = 0;
    for (int i = 1; i < x; i++)
        if (!(x % i))
            sum += i;
    return sum;
}

int main() {
  int n;
  cin >> n;
    for (int i = 1; i <= n; i++)
      num[i] = find(i);
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            f[j] = max(f[j], f[j - i] + num[i]); 
    cout << f[n];
    return 0;
}