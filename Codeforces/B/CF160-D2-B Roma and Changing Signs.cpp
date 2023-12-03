/*
Link: https://codeforces.com/contest/262/problem/B
By Soliman Elhassanein

TC: O(n)
MC: O(0)

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	IOS;
	ll n, k, sum = 0, num, smallest = LLONG_MAX;
	cin >> n >> k;
	
	while (n--) {
		cin >> num;
		if (k > 0 && num < 0) {
			num *= -1;
			k--;
		}
		smallest = min(num, smallest);
		sum += num;
	}
	if (k % 2 != 0) {
		sum -= smallest * 2;
	}
	cout << sum;
		

	

	return 0;
}
