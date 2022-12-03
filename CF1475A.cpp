#include <iostream>

using namespace std;

int main(){
\tint t;
  for (cin >> t; t--;){
\t\tlong long n;
  \tcin >> n;
  \tputs(n - (n & (-n)) ? "Yes" : "No");
  }
  return 0;
}