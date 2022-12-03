#include <iostream>

using namespace std;

int maxi(int a, int b, int c) {
    return max(a, max(b, c));
}

int mini(int a, int b, int c) {
    return max(a, min(b, c));
}

int main()
{
    int n, l, p, max = 0, min = 0;
    cin >> l >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p;
        max = maxi(max, l - p + 1, p);
        min = mini(min, l - p + 1, p);
    }
    cout << min <<  " " << max;
    return 0;
}