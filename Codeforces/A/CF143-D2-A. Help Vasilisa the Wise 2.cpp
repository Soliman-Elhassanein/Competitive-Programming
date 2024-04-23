/*
Link: https://codeforces.com/contest/143/problem/A
By Soliman Elhassanein
Date: 24 Apr 2024

TC: O(1)
MC: O(1)

*/

// Improving input/output efficiency
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
using namespace std;

/*
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
*/

#define ll long long

bool in_range(int x) {
    if (x > 9 || x < 1)
        return false;
        
    return true;
}

int main() {    
    IOS;
	
    int r1, r2, c1, c2, d1, d2, i, j, k, l;

    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;

    l = abs((c1 - d1 - r2) / 2);
    i = d1 - l;
    j = c2 - l;
    k = c1 - i;



    if (l == i || l == j || l == k) {
        cout << -1;
    }
    else if (i == l || i == j || i == k) {
        cout << -1;
    }
    else if (j == l || j == i || j == k) {
        cout << -1;
    }
    else if (!in_range(i) || !in_range(j) || !in_range(k) || !in_range(l)) {
        cout << -1;
    }
    else if (c1 != i + k || c2 != j + l || d1 != i + l || d2 != j + k || r1 != i + j || r2 != k + l) {
        cout << -1;
    }
    else {
        cout << i << " " << j << endl;
        cout << k << " " << l;
    }
}
