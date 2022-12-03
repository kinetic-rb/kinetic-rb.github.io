/*
\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227
\u3000\u3000\u3000\u3000\u3000 \u2227\uff3f\u2227 \u3000\uff08\u00b4<_\uff40 \uff09\u3000 Welcome to My Coding Space ^_^
\u3000\u3000\u3000\u3000 \uff08 \u00b4_\u309d`\uff09\u3000/\u3000 \u2312i
\u3000\u3000\u3000\u3000\uff0f\u3000\u3000\u3000\uff3c\u3000 \u3000  |\u3000|
\u3000\u3000\u3000 /\u3000\u3000 /\uffe3\uffe3\uffe3\uffe3/\u3000|\u3000|
\u3000 \uff3f_(__\uff86\u3064/\u3000\u3000 \u3000 / .| .|\uff3f\uff3f\uff3f\uff3f
\u3000 \u3000\u3000\u3000\uff3c/\uff3f\uff3f\uff3f\uff3f/\u3000\uff08u\u3000\u2283
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
using tp = int64_t;
constexpr tp Hat_M = 23;

bool Liar[Hat_M];
string Day_Def[] = {"Undef",    "Monday", "Tuesday",  "Wednesday",
                    "Thursday", "Friday", "Saturday", "Sunday"};
map<string, tp> NID;
map<tp, string> IDN;
map<tp, set<string>> TS;

signed main() {
  tp n, m, p, guilty = 0;
  cin >> n >> m >> p;
  for (tp i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    NID[s] = i;
    IDN[i] = s;
  }
  while (p--) {
    string Name, Main;
    cin >> Name;
    getline(cin, Main);
    if (Main.back() == '\r') {
      Main.pop_back();
    }
    Name.pop_back();
    Main = Main.substr(1);
    if (Main == "I am guilty." || Main == "I am not guilty." ||
        Main == "Today is Monday." || Main == "Today is Tuesday." ||
        Main == "Today is Wednesday." || Main == "Today is Thursday." ||
        Main == "Today is Friday." || Main == "Today is Saturday." ||
        Main == "Today is Sunday.") {
      TS[NID[Name]].insert(Main);
    } else {
      string Temp = "";
      for (auto&& i : Main) {
        if (i == ' ') {
          break;
        }
        Temp.push_back(i);
      }
      if (NID[Temp]) {
        bool f = 0;
        Temp.clear();
        for (auto&& i : Main) {
          if (f) {
            Temp.push_back(i);
          } else if (i == ' ') {
            f = 1;
          }
        }
        if (Temp == "is guilty." || Temp == "is not guilty.") {
          TS[NID[Name]].insert(Main);
        }
      }
    }
  }
  if (!TS.size() && n > 1) {
    cout << "Cannot Determine
";
    return 0;
  }
  for (tp i = 1; i <= m; ++i) {
    Liar[i] = 1;
  }
  reverse(Liar + 1, Liar + n + 1);
  do {
    bool NF = 1;
    for (tp day = 1; day <= 7; ++day) {
      bool Can_Not = 0;
      string F = "Today is " + Day_Def[day] + '.';
      set<string> NLIB;
      for (tp i = 1; i <= 7; ++i) {
        if (i != day) {
          NLIB.insert("Today is " + Day_Def[i] + '.');
        }
      }
      for (auto&& [x, y] : TS) {
        if (Can_Not) {
          break;
        }
        for (auto&& i : y) {
          if (Liar[x] && i == F) {
            Can_Not = 1;
            break;
          }
          if (!Liar[x] && NLIB.count(i)) {
            Can_Not = 1;
            break;
          }
        }
      }
      if (!Can_Not) {
        NF = 0;
        break;
      }
    }
    if (NF) {
      continue;
    }
    for (tp g = 1; g <= n; ++g) {
      bool f = 0;
      for (auto&& [name, say] : TS) {
        if (f) {
          break;
        }
        for (auto&& i : say) {
          set<string> NU;
          if (i == "I am not guilty." || i == "I am guilty.") {
            if (i == "I am guilty.") {
              if (Liar[name] && name == g) {
                f = 1;
                break;
              }
              if (!Liar[name] && name != g) {
                f = 1;
                break;
              }
            } else {
              if (Liar[name] && name != g) {
                f = 1;
                break;
              }
              if (!Liar[name] && name == g) {
                f = 1;
                break;
              }
            }
            continue;
          }
          for (tp d = 1; d <= 7; ++d) {
            NU.insert("Today is " + Day_Def[d] + '.');
          }
          if (!NU.count(i)) {
            bool lf = 0;
            string Name, GQ;
            for (auto&& c : i) {
              if (lf) {
                GQ.push_back(c);
              } else if (c == ' ') {
                lf = 1;
              } else {
                Name.push_back(c);
              }
            }
            if (GQ == "is guilty.") {
              if (Liar[name] && NID[Name] == g) {
                f = 1;
                break;
              }
              if (!Liar[name] && NID[Name] != g) {
                f = 1;
                break;
              }
            } else {
              if (Liar[name] && NID[Name] != g) {
                f = 1;
                break;
              }
              if (!Liar[name] && NID[Name] == g) {
                f = 1;
                break;
              }
            }
          }
        }
      }
      if (f) {
        continue;
      }
      if (guilty && guilty != g) {
        cout << "Cannot Determine
";
        return 0;
      }
      guilty = g;
      break;
    }
  } while (next_permutation(Liar + 1, Liar + n + 1));
  if (guilty) {
    cout << IDN[guilty] << '\n';
  } else {
    cout << "Impossible";
  }
  return 0;
}

/*#################################################################
#.................................................................#
#.............#......#............Created.By.RBTree...............#
#............#.#....#.#........... Limiting-Factor................#
#.............########............................................#
#............#........#..##############################...........#
#...........#..V....V......#..#........................#..#...#...#
#............#........#....#..........###..###..........#..#.#.#..#
#............#..X##X..#..#............#....#.#...........#..#...#.#
#...........#...N##N...#..#...........###..###..........#.........#
#.......MOO..#..@.....#....#.#.#.#...................#.#..........#
#.............########.....#.#.#.##############.#.#..#.#..........#
#..........................#.#.#.#.............#.#.#.#.#..........#
#......#########...........#.#.#.#.................#.#.#..........#
#.....#.........#..........#.#.#.#.................#.#.#..........#
#.#.#.#G#R#A#S#S#.#.#......#.#.#.#.................#.#.#..........#
#.###################......#.#.#.#.................#.#.#..........#
#...........................#.#.#...................#.#...........#
#.................................................................#
#################################################################*/