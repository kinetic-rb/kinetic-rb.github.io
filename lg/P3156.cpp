#include <iostream>

using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   int * stu = (int *) malloc(n * 4);
   for (int i = 0; i < n; i++)
      cin >> stu[i];
   for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      cout << stu[--x] << '\n';
   }
   return 0;
}