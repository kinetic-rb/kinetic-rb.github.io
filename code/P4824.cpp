// By rbtree (https://rbtree.archi) :\
// Please submit with C++14!
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <ctime>
#include <unordered_map>
#include <utility>
#include <vector>
#define gh1(x) ((x % MOD1) + MOD1) % MOD1
#define gh2(x) ((x % MOD2) + MOD2) % MOD2

using tp = long long;
using namespace std;
constexpr tp BST[] = {131, 431, 13331, 23333, 1333331};
constexpr tp MST[] = {1145141, 1145143, 2172179, 2179217, 19491919};

signed main() {
  tp MOD1 = MST[time(0) % 5], MOD2 = MST[time(0) % 5];
  tp BASE1 = BST[time(0) % 5], BASE2 = BST[time(0) % 5];
  tp t_hash1 = 0, t_hash2 = 0, pw1 = 1, pw2 = 1;
  string s, t, tar;
  vector<tp> tth1({0}), tth2({0});
  cin >> s >> t;
  for (auto&& i : t) {
    t_hash1 = (t_hash1 * BASE1 + i) % MOD1;
    t_hash2 = (t_hash2 * BASE2 + i) % MOD2;
    pw1 = (pw1 * BASE1) % MOD1;
    pw2 = (pw2 * BASE2) % MOD2;
  }
  for (auto&& i : s) {
    tar.push_back(i);
    tth1.push_back((tth1.back() * BASE1 + tar.back()) % MOD1);
    tth2.push_back((tth2.back() * BASE2 + tar.back()) % MOD2);
    if (tar.size() >= t.size() &&
        gh1(tth1.back() - tth1[tar.size() - t.size()] * pw1) == t_hash1 &&
        gh2(tth2.back() - tth2[tar.size() - t.size()] * pw2) == t_hash2 &&
        tar.substr(tar.size() - t.size()) == t) {
      for (tp j = 0; j < t.size(); ++j) {
        tth1.pop_back();
        tth2.pop_back();
        tar.pop_back();
      }
    }
  }
  puts(tar.c_str());
  return 0;
}