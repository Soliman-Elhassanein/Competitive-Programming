//21-June-2023

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

long long int Check(long long Max) { return ( (Max-1) * (Max + 2) ) / 2 - Max+2; }

long long int Formula(long long Max, long long Num) {return ( Num * (Max-1 + (Max-Num)) ) / 2 + 1;}

int main() {
    
    long long n, k, start = 1, mid, end, result = -1, counter = 0;

    cin >> n >> k;

    end = k-1;
    
    if (Check(k) < n) cout << -1;
    else if (n == 1) cout << 0;
    else {
        while (start < end) {
            counter++;
            mid = (end + start) / 2;
            result = Formula(k, mid);
            if (result >= n) end = mid;
            else start = mid + 1;
        }
        cout << end;
    }
    
    return 0;
}
