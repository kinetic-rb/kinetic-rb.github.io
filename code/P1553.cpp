#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int type = 1;  // \u90a3\u79cd\u7c7b\u578b : 1 \u662f\u6574\u6570\uff0c2 \u662f\u5c0f\u6570\uff0c3 \u662f\u5206\u6570\uff0c4 \u662f\u767e\u5206\u6570
  string x;
  cin >> x;
  for (auto& i : x)  // \u5224\u65ad\u7c7b\u578b
    if (i == '.') {  // \u5224\u65ad\u4e3a\u5c0f\u6570
      type = 2;
      break;
    } else if (i == '/') {  // \u5224\u65ad\u4e3a\u5206\u6570
      type = 3;
      break;
    } else if (i == '%') {  // \u5224\u65ad\u4e3a\u767e\u5206\u6570
      type = 4;
      break;
    }
  if (type == 1 || type == 4) {
    if (type == 4)
      x.pop_back();
    while (*(x.end() - 1) == '0')  //  \u53bb\u6389\u672b\u5c3e\u7684 0 \u56e0\u4e3a\u5b83\u7ffb\u8f6c\u540e\u53d8\u6210\u9996\u4f4d\u7684 0
      x.pop_back();
    if (x == "")  // \u5982\u679c\u6570\u503c\u672c\u6765\u5c31\u662f 0
      x.push_back('0');
    reverse(x.begin(), x.end());
    cout << x;
    if (type == 4)
      putchar('%');
    return 0;
  }
  if (type == 2) {
    int xf;
    for (int i = 0; i < x.size(); i++)
      if (x[i] == '.')
        xf = i;
    // \u4ee5\u4e0a\u627e\u5230\u5206\u754c\u70b9
    string temp = x.substr(0, xf);
    while (*(temp.end() - 1) == '0')
      temp.pop_back();
    if (temp == "")
      temp.push_back('0');
    reverse(temp.begin(), temp.end());
    cout << temp + '.';
    temp = x.substr(xf + 1, x.size());
    if (temp == "")
      temp.push_back('0');
    reverse(temp.begin(), temp.end());
    while (*(temp.end() - 1) == '0')
      temp.pop_back();
    if (temp == "")
      temp.push_back('0');
    cout << temp;
    return 0;
  }
  // \u5206\u6570
  int xf;
  for (int i = 0; i < x.size(); i++)
    if (x[i] == '/')
      xf = i;
  string temp = x.substr(0, xf);
  while (*(temp.end() - 1) == '0')
    temp.pop_back();
  if (temp == "")
    temp.push_back('0');
  reverse(temp.begin(), temp.end());
  cout << temp + '/';
  temp = x.substr(xf + 1, x.size());
  while (*(temp.end() - 1) == '0')
    temp.pop_back();
  if (temp == "")
    temp.push_back('0');
  reverse(temp.begin(), temp.end());
  cout << temp;
  return 0;
}