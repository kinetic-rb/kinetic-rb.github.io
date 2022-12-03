#include <iostream>
#include <string>

using namespace std;

bool cs(char item) {
    if(item != 'C' && item != 'A' && item != 'M' && item != 'B' && item != 'R' && item != 'I' && item != 'D' && item != 'G' && item != 'E')
        return true;
    return false;
}

int main() {
    string x;
    cin >> x;
    for(auto item : x) {
        if(cs(item))
            cout << item;
    }
    return 0;
}