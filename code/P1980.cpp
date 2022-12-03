#include <iostream>

using namespace std;

int main()
{
    int L = 1, R, ans = 0, x;
    for(cin >> R >> x; L <= R; L++)
        for(int i = L; i; i /= 10)
            if(i % 10 == x)
                ans++;
    cout << ans;
    return 0;
}