#include <iostream>
#include <iomanip>

using namespace std;

double pai=3.1415926;

int main(){
  double a;
  cin >> a;
  cout << fixed << setprecision(3) << a * pai * a;
}