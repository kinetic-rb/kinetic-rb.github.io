#include <iostream> // cin \u548c cout
#include <set> // set\uff0c\u6211\u8fd9\u91cc\u7528 set \u5224\u65ad\u4e00\u4e2a\u70b9\u662f\u5426\u5df2\u7ecf\u88ab\u5e7f\u64ad\u5230
#include <cmath> // abs \u548c sqrt

using namespace std;

struct COW { // \u6bcf\u5934\u5976\u725b
    int x, y, p; // \u5750\u6807\u548c\u80fd\u5e7f\u64ad\u5230\u591a\u8fdc
} cow[205];

int n;

inline double cloc(const COW& x, const COW& y) { // \u8fd9\u4e2a\u51fd\u6570\u7528\u6765\u8ba1\u7b97\u4e24\u5934\u5976\u725b\u4e4b\u95f4\u7684\u8ddd\u79bb
    int locx = abs(x.x - y.x), locy = abs(x.y - y.y); //  \u5206\u522b\u8868\u793a\u4e24\u5934\u5976\u725b\u4e4b\u95f4\u7684\u6a2a\u8ddd\u79bb\u548c\u7eb5\u8ddd\u79bb
    return sqrt(locx * locx + locy * locy); // \u52fe\u80a1\u5b9a\u7406\u6c42\u76f4\u7ebf\u8ddd\u79bb
}

set<int> net; // \u4ece\u67d0\u4e2a\u70b9\u80fd\u5e7f\u64ad\u5230\u7684\u6240\u6709\u5976\u725b\u7684\u96c6\u5408

inline void dfs(COW s) { // \u4ee5\u5976\u725b s \u4e3a\u8d77\u70b9\u80fd\u5e7f\u64ad\u5230\u90a3\u4e9b\u5976\u725b
    for (int i = 0; i < n; i++) { // \u679a\u4e3e\u6bcf\u5934\u5976\u725b
        if (cloc(cow[i], s) <= s.p && net.find(i) == net.end()) { // \u80fd\u5e7f\u64ad\u5230\u8fd9\u5934\u5976\u725b\uff08\u8ddd\u79bb\u5c0f\u4e8e\u7b49\u4e8e s.p\uff09\u5e76\u4e14\u6ca1\u6709\u5728\u96c6\u5408\u4e2d\u51fa\u73b0\u8fc7
            net.insert(i); // \u628a\u8fd9\u5934\u5976\u725b\u7684\u7f16\u53f7\u52a0\u5165\u96c6\u5408
            dfs(cow[i]); // \u7ee7\u7eed\u5e7f\u64ad
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int MAX = 0; // \u6700\u5927\u5e7f\u64ad\u5976\u725b\u6570\u91cf
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i].x >> cow[i].y >> cow[i].p;
    for (int i = 0; i < n; i++) { // \u679a\u4e3e\u6bcf\u5934\u5976\u725b\u4f5c\u4e3a\u8d77\u59cb\u70b9
        net.clear(); // \u6e05\u7a7a\u96c6\u5408
        dfs(cow[i]); // \u5f00\u59cb\u5e7f\u64ad
        if (net.size() > MAX) // \u66f4\u65b0\u6700\u5927\u503c
            MAX = net.size();
    }
    cout << MAX; // \u8f93\u51fa\u7b54\u6848
    return 0;
}