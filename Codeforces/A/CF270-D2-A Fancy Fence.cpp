#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int a, x;

    cin >> x;

    while (x) {
        x--;
        cin >> a;
        if (360 % (180 - a) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
