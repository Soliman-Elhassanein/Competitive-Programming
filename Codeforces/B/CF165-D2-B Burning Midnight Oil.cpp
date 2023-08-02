/*
Date: 02 Aug 2023
TC: O(Log n)
MC: O(1)
*/

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

int GetNumberOfLines(int v, int k) {
    int lines = 0;
    int l = v;
    int counter = 0;
    while (l != 0) {
        l = v / pow(k, counter);
        lines += l;
        counter++;
    }
    return lines;
}

int main() {
    
    long int n, k, mid, start, end, lines, past;
    cin >> n >> k;

    start = 1;
    end = n;
    past = 0;
    lines = 1;
    while (past != lines) {
        past = lines;
        mid = (start + end) * 1 / 2;
        lines = GetNumberOfLines(mid, k);
        if (lines > n)
            end = mid;
        else if (lines < n)
            start = mid;
        else
            break;
    }
    
    if (past == lines && lines < n)
        cout << mid + 1;
    else
        cout << mid;
    
    return 0;
}
