#include <iostream>

using namespace std;

int main(){
  int t;
  for (cin >> t; t--;){
    long long n;
    cin >> n;
    puts(n - (n & (-n)) ? "Yes" : "No");
  }
  return 0;
}