#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int x;
  double a, b;
  cin >> x;
  a = x / 3.0 + 50;
  b = x / 1.2;
  if(a > b) {
      cout << "Walk";
      exit(0);
  }
  if(a<b) {
      cout << "Bike";
      exit(0);
  }
  cout << "All";
  exit(0);
}