#if false
#include <fstream>
std::ifstream cin("loc.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif
#include <string>

using namespace std;

int main() {
  unsigned long long foundloc, cnt = 0;
  string fw, text;
  getline(getline(cin, fw), text);
  for (auto& i : fw)
    i = tolower(i);
  for (auto& i : text)
    i = tolower(i);
  fw = ' ' + fw + ' ';
  text = ' ' + text + ' ';
  foundloc = text.find(fw);
  if (foundloc == string::npos) {
    cout << -1;
    return 0;
  }
  for (auto loc = foundloc; loc != string::npos; loc = text.find(fw, loc + 1))
    cnt++;
  cout << cnt << ' ' << foundloc;
  return 0;
}