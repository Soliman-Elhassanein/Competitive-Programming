/*
14-Nov-2023
TC: O(n)
SC: O(n)
*/

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, ri, li, counter = 0;

    cin >> n >> a;

    ri = li = a-1;

    vector<int> c(n);

    for (auto& i : c){
        cin >> i;
    }

    auto inRange = [](const vector<int>& vec, int index) {
        return index >= 0 && index < vec.size() ? true : false;
    };

    while (inRange(c,ri) || inRange(c,li) ) {

        if (inRange(c, ri) && inRange(c, li)) {
            if (ri == li && c[li])
                counter++;
            else if (c[li] && c[ri])
                counter += 2;
        }
        else if (inRange(c, li)) {
            if (c[li])
                counter++;
        }
        else if (inRange(c, ri)) {
            if (c[ri])
                counter++;
        }

        li++;
        ri--;
    }

    cout << counter;

    return 0;
}
