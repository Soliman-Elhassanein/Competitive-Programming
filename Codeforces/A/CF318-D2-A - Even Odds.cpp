//07-Jun-2023

//TC: O(1)
//MC: O(1)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k, half, output;

    cin >> n >> k;

    half = ceil(n / 2.0);

    if (k > half)
        output = (k - half) * 2;
    else
        output = k * 2 - 1;

    cout << output;

    return 0;
}
