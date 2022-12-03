#include <iostream>

using namespace std;

int a[1000005] = {1}, b[1000005] = {1};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    \ta[i] = (b[i - 1] - (i - m < 1 ? 0 : b[i - m - 1]) + 1000000007) % 1000000007;
    \tb[i] = (b[i - 1] + a[i]) % 1000000007;
    }
    cout<< a[n];
    return 0;
}