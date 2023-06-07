//08-Jun-2023

//TC: O(1)
//MC: O(1)

//#208938642

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int l, r, a, b, c;
    cin >> l >> r;

    if ( (r-l < 2 && l%2 == 0) || (r-l < 3 && l%2 != 0) ) {
        cout << -1;
        return 0;
    }

    if (l & 1)
        a = l + 1;
    else
        a = l;
       
    b = a + 1;
    c = a + 2;

    cout << a << " " << b << " " << c;

    return 0;
}
