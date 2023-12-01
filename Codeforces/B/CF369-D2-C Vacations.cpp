/*
Link: https://codeforces.com/contest/699/problem/C

By Soliman Elhassanein

TC: O(n)

MC: O(0)
*/



// Improving input/output efficiency
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {IOS;
    int n;
    cin >> n;

    int last = 0, rest = 0, event;

    for (int i = 0; i < n; i++)
    {
        cin >> event;

        if (event == 0) {
            rest++;
            last = 0;
        }
        else if (event == 1) {
            if (last != 1)
                last = 1;
            else {
                rest++;
                last = 0;
            }
        }
        else if (event == 2) {
            if (last != 2)
                last = 2;
            else {
                rest++;
                last = 0;
            }
        }
        else if (event == 3) {
            if (last == 1)
                last = 2;
            else if (last == 2)
                last = 1;
        }
    }

    cout << fixed << rest;

    return 0;
}
