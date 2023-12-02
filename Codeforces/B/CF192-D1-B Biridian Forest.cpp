/*
Link: https://codeforces.com/contest/329/problem/B
By Soliman Elhassanein

TC: O[ (r*c)^2 ]
MC: O[ 2(r*c) ]

*/



/*
Link: https://codeforces.com/contest/329/problem/B
By Soliman Elhassanein

TC: O[ (r*c)^2 ]
MC: O[ 2(r*c) ]

*/



// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int BFS(vector<vector<char>> map, pair<int, int> End) {

	vector<vector<char>> map_e(map.size(), vector<char>(map[0].size(), 0));
	queue<pair<int, int>> current, next;
	int monks = 0;
	current.push(End);
	int counter = 0;
	bool flag = true;
	do
	{
		while (current.size()) {
			if (map[current.front().first][current.front().second] == 'S')
				flag = false;

			if (map_e[current.front().first][current.front().second] == 0) {
				map_e[current.front().first][current.front().second] = 1;


				for (int i = 0; i < 4; ++i) {
					int x = (i == 2) - (i == 3);
					int y = (i == 0) - (i == 1);

					if (map.size() > current.front().first + x && map[0].size() > current.front().second + y && -1 < current.front().first + x && -1 < current.front().second + y)
						if (map[current.front().first + x][current.front().second + y] != 'T')
							next.push({ current.front().first + x, current.front().second + y});
				}

				if (map[current.front().first][current.front().second] != 'S' && map[current.front().first][current.front().second] != 'E')
					monks += map[current.front().first][current.front().second] - '0';

			}

			current.pop();
		}
		if (flag)
			current.swap(next);

	} while (flag);

	return monks;

}

int main() {
	IOS;

	int r, c;
	cin >> r >> c;
	char temp;

	vector<vector<char>> map(r, vector<char>(c, 0));
	pair<int, int> End;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 'E')
				End = { i, j };
		}
	}

	cout << BFS(map, End);;

	return 0;
}
