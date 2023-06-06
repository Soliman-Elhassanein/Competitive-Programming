//06-Jun-2023

//TC: O(1)
//MC: O(1)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    float n, t, k, d, Number, TotalTime2;

    cin >> n >> t >> k >> d;

    Number = ceil(n / k);

    if (t * (Number - 1) > d)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
