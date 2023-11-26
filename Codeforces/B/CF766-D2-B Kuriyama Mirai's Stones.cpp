/*
By Soliman Elhassanein
TC: O(2n)
MC: O(2n)
*/


#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	// Improving input/output efficiency
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n, m, type, l, r;
	cin >> n;
	vector<ll> prefixsum(n + 1);
	vector<ll> prefixsumsorted(n + 1);
	prefixsum[0] = 0;
	prefixsumsorted[0] = 0;

	for (int i = 1; i < n+1; i++) {
		cin >> prefixsumsorted[i];
		prefixsum[i] = prefixsumsorted[i] + prefixsum[i - 1];
	}

	sort(prefixsumsorted.begin() + 1, prefixsumsorted.end());
	
	for (int i = 1; i < n+1; i++){
		prefixsumsorted[i] = prefixsumsorted[i] + prefixsumsorted[i - 1];
	}

	cin >> m;

	while (m--) {
		cin >> type >> l >> r;

		if (type == 1){
			cout << fixed << prefixsum[r] - prefixsum[l-1] << endl;
		}
		else {
			cout << fixed << prefixsumsorted[r] - prefixsumsorted[l-1] << endl;
		}
	}
	return 0;
}
