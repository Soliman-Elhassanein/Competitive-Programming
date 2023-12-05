/*
Link: https://codeforces.com/contest/60/problem/B
29 Nov 2023
By Soliman Elhassanein

TC(n*m*k)
MC(n*m*k)


*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long


int DFS(vector<vector<vector<char>>>& plate, int k, int n, int m, vector<vector<vector<char>>>& water) {
	int count = 0;
	water[k][n][m] = 1;

	if (plate[k][n][m] == '.') {
		count += 1;
		
		if (n + 1 < plate[0].size() && !water[k][n + 1][m])
			count += DFS(plate, k, n + 1, m, water);
		if (n - 1 > -1 && !water[k][n - 1][m])
			count += DFS(plate, k, n - 1, m, water);
		
		if (m + 1 < plate[0][0].size() && !water[k][n][m + 1])
			count += DFS(plate, k, n, m + 1, water);
		if (m - 1 > -1 && !water[k][n][m - 1])
			count += DFS(plate, k, n, m - 1, water);

		if (k + 1 < plate.size() && !water[k + 1][n][m])
			count += DFS(plate, k + 1, n, m, water);
		if (k - 1 > -1 && !water[k - 1][n][m])
			count += DFS(plate, k - 1, n, m, water); 
	}
	return count;
}



int main() {IOS;

	int k, n, m, x, y, count = 0;
	cin >> k >> n >> m;
	char temp;

	vector<vector<vector<char>>> plate(k, vector<vector<char>>(n, vector<char>(m)));
	vector<vector<vector<char>>> water(k, vector<vector<char>>(n, vector<char>(m, 0)));

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				cin >> plate[i][j][l];
			}
		}
	}

	cin >> x >> y;

	count = DFS(plate, 0, x - 1, y - 1, water);
	cout << count;

	return 0;
}
