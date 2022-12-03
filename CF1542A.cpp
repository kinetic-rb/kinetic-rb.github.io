#include <iostream>
 
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false);
    signed t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        signed n, oc = 0, ec = 0;
        cin >> n;
        n *= 2;
        for(int j = 0; j < n; j++) {
            signed x;
            cin >> x;
            (x & 1) ? oc++ : ec++;
        }
        (oc == ec) ? cout << "Yes
" : cout << "No
";
    }
    return 0;
}