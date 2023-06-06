//06-Jun-2023

//Solution 1
//TC: O(1)
//MC: O(1)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Limak, Bob, i;
    double d;
    cin >> Limak >> Bob;

    i = ceil( log((double)Bob / Limak) / log(3.0 / 2.0) );
    d = log((double)Bob / Limak) / log(3.0 / 2.0);
    
    if (i == d) 
        i++;

    cout << i;

    return 0;
}


/*
//Solution 2
//TC: O(log(Bob / Limak))
//MC: O(1)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Limak, Bob, counter = 0;

    cin >> Limak >> Bob;

    while (Limak <= Bob) {
        Bob *= 2;
        Limak *= 3;
        counter++;
    }

    cout << counter;

    return 0;
}
*/
