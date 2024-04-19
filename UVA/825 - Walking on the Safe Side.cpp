/*
Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=766
By Soliman Elhassanein
Date: 19 Apr 2024

TC: O(N * M)
MC: O(N * M)

*/

// Improving input/output efficiency
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> ways(10000, 0);

void dfs(vector<vector<ll>> map, ll dir, pair<int, int> cur, ll count) {
    ll rows = map.size();
    ll cols = map[0].size();
    
    if (dir == 1)
        cur.first++;
    else
        cur.second++;

    if (cur.first > rows - 1 || cur.second > cols - 1)
        return;

    if (map[cur.first][cur.second] == -1)
        return;

    if (cur.first == rows - 1 && cur.second == cols - 1) {
        ways[count]++;
    }

    dfs(map, 1, cur, ++count);
    dfs(map, 2, cur, count);

}

int main() {    
    IOS;
	
    ll num_test, tmp1, tmp2;
    string tmp0;
    cin >> num_test;
    
    while(num_test--){
        ll rows, cols;
        cin >> rows >> cols;
        
        vector<vector<ll>> row(rows, vector<ll>(cols, 0));
        
        while (rows-- + 1){
            getline(cin, tmp0);
            stringstream sin(tmp0);
            sin >> tmp2;
            while(sin >> tmp1){
                row[tmp2-1][tmp1-1] = -1;
            }
        }
        dfs(row, 1, {0 ,0}, 0);
        dfs(row, 2, {0 ,0}, 0);

        int num = ways[0];
        int counter = 0;
        while (!num) {
            counter++;
            num = ways[counter];
        }

        cout << num;
    }
}
