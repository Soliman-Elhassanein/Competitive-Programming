/*
15-Nov-2023
TC: O(n)
MC: O(n)
*/



#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;

    cin >> n >> l;

    vector<long long> h(n);
    for (auto& i : h)
        cin >> i;

    sort(h.begin(), h.end() );
    
    long double mx = max(h[0], l - h[n - 1] );

    for (int i = 0; i < n-1; i++){
        mx = max(mx,  (h[i + 1] - h[i]) / 2.0L );
    }

    cout << fixed << mx;
    return 0;
}
