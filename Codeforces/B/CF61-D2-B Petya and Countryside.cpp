/*
  13-Nov-2023
  C = O(n)
  S = O(n)
  
*/

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0, f = 0, max = 1, max_t = 1, s = 0;
    cin >> n;

    vector<int> h(n);

    for (auto &element : h)
        cin >> element;

    cout << "";

    for (int i = 0; i < n - 1; i++) {

        if (h[i] == h[i + 1]) {
            s++;
            max_t++;
        }
        //p=i, c=i
        else if (h[i] < h[i + 1] && m == 0) {
            m = 0;
            s = 0;
            max_t++;
        }
        //c=d
        else if (h[i] > h[i + 1]) {
            max_t++;
            m = 1;
            s = 0;
        }
        //p=d, c=i
        else if (h[i] < h[i + 1] && m == 1) {
            if (max < max_t)
                max = max_t;

            max_t = 2 + s;
            s = 0;
            m = 0;
        }
    }
    if (max_t > max)
        max = max_t;

    cout << max;
    return 0;
}
