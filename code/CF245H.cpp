#include <cstdio>
#include <cstring>

char s[5005];

void get_input() {
    scanf("%s", s + 1);
}

bool is_pal[5005][5005];
bool visit_pal[5005][5005];

void get_is_pal(int l, int r) {
    if(visit_pal[l][r])
        return;
    
    if(l == r || r == l+1) {
        is_pal[l][r] = (s[l] == s[r]);
        return;
    }

    get_is_pal(l+1, r-1);
    if(is_pal[l+1][r-1])
        is_pal[l][r] = (s[l] == s[r]);
    // [l, r] \u662f\u56de\u6587\u5b50\u4e32\u5f53\u4e14\u4ec5\u5f53 [l+1, r-1] \u662f\u56de\u6587\u5b50\u4e32\uff0c\u4e14 s[l]=s[r]

    visit_pal[l][r] = true;
}

int dp[5005][5005];
bool visit_dp[5005][5005];

void get_dp(int l, int r) {
    if(visit_dp[l][r])
        return;

    if(l == r) {
        dp[l][r] = 1;
        return;
    }
    if(r == l + 1) {
        // \u957f\u5ea6\u662f2\uff0c\u4e24\u79cd\u60c5\u51b5\uff1aab, \u7b54\u6848\u662f2\uff1baa, \u7b54\u6848\u662f3
        dp[l][r] = 2 + is_pal[l][r];
        return;
    }

    get_dp(l, r-1);
    get_dp(l+1, r);
    get_dp(l+1, r-1);

    dp[l][r] = dp[l][r-1] + dp[l+1][r] - dp[l+1][r-1] + is_pal[l][r];
    
    visit_dp[l][r] = true;
}

void init() {
    int len_s = strlen(s+1);

    for(int x=1; x<=len_s; x++)
        for(int y=x; y<=len_s; y++)
            get_is_pal(x, y);
    
    for(int x=1; x<=len_s; x++)
        for(int y=x; y<=len_s; y++)
            get_dp(x, y);
}

void output_answer() {
    int q, l, r;
    scanf("%d", &q);

    while(q--) {
        scanf("%d%d", &l, &r);
        printf("%d
", dp[l][r]);
    }
}

int main(void) {
    get_input();
    init();
    output_answer();

    return 0;
}
