//02-Jun-2023
//TC: O(n + m)
//MC: O(n)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;


void DFS(int node, vector<vector<int>>& enemy, set<int>& bench, vector<int>& team) {
    
    for (auto e : enemy[node]) {
        if (bench.find(e) != bench.end())
            continue;
        if (team[node] == team[e]) {
            bench.insert(node);
            return;
        }
        if (team[e] == 0) {
            team[e] = (team[node] % 2) + 1;
            DFS(e, enemy, bench, team);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> enemy(n);
    vector<int> team(n,0);
    set<int> bench;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        enemy[x-1].push_back(y-1);
        enemy[y-1].push_back(x-1);
    }

    for (int i = 0; i < n; i++) {

        if (team[i] == 0) {
            team[i] = 1;
            DFS(i, enemy, bench, team);
        }
    }

    cout << bench.size() + (n - bench.size()) % 2 << endl;

    return 0;
}
