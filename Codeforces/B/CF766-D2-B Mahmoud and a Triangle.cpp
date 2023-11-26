#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	// Improving input/output efficiency
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	ll n, is, ie,i;
	cin >> n;
	vector<ll> sides(n);

	for (auto& i : sides) cin >> i;

	sort(sides.begin(), sides.end());

	for (int i = 0; i < n-2; i++){
		if (sides[i + 2] < sides[i + 1] + sides[i]) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
