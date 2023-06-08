//08-Jun-2023

//TC: O(n)
//MC: O(n)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

double Distance(pair<int, int> point1, pair<int, int> point2) {
	return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}

int main() {
	
	int n, k;
	double Total = 0;
	cin >> n >> k;

	vector<pair<int, int>> points(n);

	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;

		if (i > 0) {
			Total += Distance(points[i], points[i - 1]);
		}
	}

	cout << setprecision(10);
	cout << (Total/ 50)*k;

	return 0;
}
