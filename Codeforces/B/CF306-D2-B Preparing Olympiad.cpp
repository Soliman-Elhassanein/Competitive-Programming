/*
Link: https://codeforces.com/contest/550/problem/B
By Soliman Elhassanein
Date: 09 Dec 2023

TC: O(2^n -1)
MC: O( n )

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve(vector<ll> p, int j, ll l, ll r, ll x, ll smallest, ll sum) {
	ll count = 0;
	for (; j < p.size(); j++) {
		if (p[j] + sum >= l && p[j] + sum <= r && p[j] - smallest >= x) {
			count += 1;
			if (j + 1 < p.size())
				count += solve(p, j + 1, l, r, x, smallest, p[j] + sum);
		}
		else if (p[j] + sum < r) {
			if (j + 1 < p.size())
				count += solve(p, j + 1, l, r, x, smallest, p[j] + sum);
		}
		else if (p[j] + sum > r)
				break;
	}
	return count;
}

int main() {
	IOS;
	/*
		n: the number of problems you have
		l: the minimum difficulty of the problemset
		r: the maximum difficulty of the problemset
		x: the minimum difference in difficulty between the hardest problem in the pack and the easiest one
	*/

	ll n, l, r, x, temp, count = 0;

	cin >> n >> l >> r >> x;

	vector<ll> p(n, 0);

	for(auto& i: p)
		cin >> i;

	sort(p.begin(), p.end());

	for (int i = 0; i < p.size() - 1; i++){
		count += solve(p, i + 1, l, r, x, p[i], p[i]);
		
	}

	cout << count;
	return 0;
}
