/*
Link: https://codeforces.com/contest/716/problem/B
By Soliman Elhassanein

TC: O(n)
MC: O(1)

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	IOS;

	/*
		n: number of students
		k: number of top students
		l: min points
		r: max points
		s_all: total points of the team
		s_k: total of k students

		s_s: s_all - s_k
		s = n - k

		s_k = ax
	*/


	ll n, k, l, r, s_all, s_k, coff, remained, temp, z;
	vector<ll> values;

	cin >> n >> k >> l >> r >> s_all >> s_k;

	coff = r;
	ll s_s = s_all - s_k;
	ll s = n - k;

	coff = s_k / k;
	remained = s_k - (coff * k);
	int i = 0;

	while (s_k) {
		temp = ceil(remained / float(k - i));
		values.push_back(coff + temp);
		remained -= temp;
		s_k -= coff + temp;
		i++;
	}

	if (s_s) {
		i = 0;
		coff = s_s / s;
		remained = s_s - (coff * s);

		while (s_s) {
			temp = ceil(remained / float(s - i));
			values.push_back(coff + temp);
			remained -= temp;
			s_s -= coff + temp;
			i++;
		}
	}
	

	for (auto& i : values)
		cout << i << " ";

	return 0;
}
