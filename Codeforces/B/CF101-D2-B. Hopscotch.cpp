/*
Link: https://codeforces.com/contest/141/problem/B
By Soliman Elhassanein
Date: 18 Dec 2023

TC: O( 0 )
MC: O( 0 )

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
/*
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	IOS;

	ll a, x, y, x_a, y_a;
	long double v_y, v_x;
		
	cin >> a >> x >> y;

	x_a = abs(x); y_a = abs(y);

	v_y = y_a / (long double)a;
	v_x = x_a / (long double)a;
	v_y = int(y_a / a) + 0.5;
	if (x_a < a / 2.0 && y_a % a != 0 && (v_y < 1 || (int)ceil(v_y) % 2 == 0)) {
		if (v_y < 1) {
			cout << 1;
		}
		else {
			cout << fixed << (int)floor(v_y * 3.0 / 2.0);
		}
		
	}
	else if (x_a < a && x_a != 0 && y_a % a != 0 && (int)ceil(v_y) % 2 == 1 && ceil(v_y) != 1) {
		if (x > 0) {
			cout << fixed << (int)ceil(v_y * 3.0 / 2.0);
		}
		else {
			cout << fixed << (int)floor(v_y * 3.0 / 2.0);
		}
	}
	else
		cout << -1;

	return 0;
}
