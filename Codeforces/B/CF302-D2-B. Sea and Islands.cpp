/*
Link: https://codeforces.com/contest/544/problem/B
By Soliman Elhassanein
Date: 17 Dec 2023

TC: O( n^2 )
MC: O( n^2 )

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	IOS;

	ll n, k;
	bool f;

	cin >> n >> k;

	vector<vector<char>> m(n, vector<char>(n, 'S'));

	if (k > (int)ceil(n * n / 2.0)) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!k)
				break;

			for (int j = 0; j < n; j++) {
				if (!k)
					break;
				
				f = true;
				
				for (int k = 0; k < 4; k++) {
					int x = (k == 2) - (k == 3);
					int y = (k == 0) - (k == 1);

					if (j + y < n && j + y > -1 && i + x < n && i + x > -1) {
						if (m[i + x][j + y] != 'S') {
							f = false;
							break;
						}
					}
				}

				if (!f)
					continue;

				m[i][j] = 'L';
				k--;
				j++;
			}
		}

		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
