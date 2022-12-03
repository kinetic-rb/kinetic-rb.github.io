#include <iostream>

int main() {
    int k;
    bool yes = false;
    std :: cin >> k;
    for(int i = 10000; i < 30001; i++) {
        int sub1, sub2, sub3;
        sub1 = i % 1000;
        sub2 = i % 10000 / 10;
        sub3 = i / 100;
        if(sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
            std :: cout << i << std :: endl;
            yes = true;
        }
        //std :: cout << sub1 << " " << sub2 << " " << sub3 << std :: endl;
    }
    if(!yes) {
        std :: cout << "No";
    }
    return 0;
}