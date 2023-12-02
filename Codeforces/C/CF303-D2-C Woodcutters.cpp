/*
link: https://codeforces.com/contest/545/problem/C

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
	ll count = 2, prev, n, h_p, h_c, cur, next, h_n;
	cin >> n;

	cin >> prev;
	cin >> h_p;
	cin >> cur;
	cin >> h_c;

	if (n == 1)
		count = 1;

	for (ll i = 1; i < n-1; i++)
	{
		cin >> next;
		cin >> h_n;

		if (prev < cur - h_c) {
			count++;
			prev = cur;
		}
		else if (next > cur + h_c) {
			prev = cur + h_c;
			count++;
		}
		else {
			prev = cur;
		}

		cur = next;
		h_c = h_n;

	}

	cout << count;

	return 0;
}
