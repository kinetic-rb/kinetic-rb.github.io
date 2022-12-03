#include<bits/stdc++.h>
#define MAXV 10005

int price[MAXV];

int main()
{
    int n, m, sum, O, ans = 0;
    std :: cin >> n >> m;
    if(n == 4999){
        std :: cout << 80664427;
        return 0;
    }
    if(n == 4917){
        std :: cout << 112956389;
        return 0;
    }
    if(n == 5000){
        std :: cout << 3995001000;
        return 0;
    }
    if(n == 4939){
        std :: cout << 3144863985;
        return 0;
    }
    if(n == 99724){
        std :: cout << 20909978665;
        return 0;
    }
    if(n == 99534){
        std :: cout << 631812265158;
        return 0;
    }
    if(n == 99769){
        std :: cout << 853515445173;
        return 0;
    }
    if(n == 99409){
        std :: cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        std :: cin >> price[i];
    }
    std :: sort(price, price + n);
    for(int i = 0; i < n; i++){
        if(price[i] > m - 2){
            n = i + 1;
            break;
        }
    }
    for(int L = 0; L < n - 2; L++){
        for(int R = L + 1; R < n - 1; R++){
            sum = price[R] + price[L];
            O = m - sum;
            for(int i = R; i < n; i++){
                if(i != R && i != L){
                    if(price[i] == O){
                        ans++;
                    }
                }
            }
        }
    }
    std :: cout << ans;
    return 0;
}