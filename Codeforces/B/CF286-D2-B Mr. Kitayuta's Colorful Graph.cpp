/*
Link:
By Soliman Elhassanein
Date:

TC: O(   )
MC: O(   )

*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long


bool contains(queue<int> q, int value) {
	while (!q.empty()) {
		if (q.front() == value) {
			return true; // Value found
		}
		q.pop();
	}
	return false; // Value not found
}


int BFS(vector<vector<vector<bool>>> map, int n, int m, int from, int to) {
	int color, cur_ver, count = 0;
	queue<int> q_c, q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[to][i][j] && !contains(q_c, j))
				q_c.push(j);
		}
	}

	while (q_c.size()) {

		for (int i = 0; i < n; i++) {
			if (!map[from][i][q_c.front()]) {
				map[from][i][q_c.front()] = true;
				map[i][from][q_c.front()] = true;
				q.push(i);
			}
		}

		while (q.size()) {

			cur_ver = q.front();
			q.pop();

			for (int i = 0; i < n; i++) {

				if (cur_ver == to) {
					count++;
					break;
				}
				else if (!map[cur_ver][i][q_c.front()]) {
					q.push(i);
					map[cur_ver][i][q_c.front()] = true;
					map[i][cur_ver][q_c.front()] = true;
				}
			}
		}
		
		q_c.pop();
		queue<int>().swap(q);
	}

	return count;
}


int main() {
	IOS;

	int n, m, q, v1, v2, v3;

	cin >> n >> m;

	vector<vector<vector<bool>>> map(n, vector<vector<bool>>(n, vector<bool>(m, true)));

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> v3;
		v1 -= 1; v2 -= 1; v3 -= 1;

		map[v1][v2][v3] = false;
		map[v2][v1][v3] = false;
	}

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> v1 >> v2;
		v1 -= 1; v2 -= 1;
		cout << BFS(map, n, m, v1, v2) << endl;
	}


	
	return 0;
}
