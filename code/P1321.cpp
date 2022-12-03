#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0;
    string x;
    cin >> x;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'b' || x[i + 1] == 'o' || x[i + 2] == 'y')
            a++;
        if (x[i] == 'g' || x[i + 1] == 'i' || x[i + 2] == 'r' || x[i + 3] == 'l')
            b++;
    }
    cout << a << "\n" << b;
    return 0;
}