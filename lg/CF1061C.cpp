#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MOD 1000000007

int n, a[100005];

void get_input() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
}

int dp[100005];

vector <int> fac;

void get_factor(int x) {    // \u5206\u89e3 x\uff0c\u56e0\u5b50\u653e\u8fdb fac
    for(int i=1; i*i<=x; i++) {
        if(x%i == 0) {
            fac.push_back(i);

            if(x != i*i)
                fac.push_back(x / i);
        }
    }
    // \u6211\u4eec\u653e\u8fdb\u53bb\u7684\u987a\u5e8f\uff1a1, x, 2, x/2.... \u65e0\u5e8f\u72b6\u6001

    sort(fac.begin(), fac.end(), greater<int>());
}

void calc_answer() {
    dp[0] = 1;          // \u6700\u5f00\u59cb\uff0c\u4ece0\u4e2a\u91cc\u9762\u90090\u4e2a\uff0c\u65b9\u6848\u6570\u4e3a1

    for(int x=1; x<=n; x++) {
        get_factor(a[x]);   // \u56e0\u6570\u653e\u5728\u4e86 fac

        for(auto y: fac)
            if(y <= x)
                dp[y] = (dp[y] + dp[y-1]) % MOD;

        fac.clear();
    }

    // \u7b54\u6848\u662f sum(dp[y])

    int ans = 0;
    for(int x=1; x<=n; x++)
        ans = (ans + dp[x]) % MOD;
    
    printf("%d", ans);
}

int main(void) {
    get_input();
    calc_answer();
    
    return 0;
}