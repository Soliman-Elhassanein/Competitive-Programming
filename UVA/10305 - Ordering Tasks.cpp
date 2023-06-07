//07-Jun-2023

//TC: O(n*m)
//MC: O(n)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

void DepthFirstSearch(vector<vector<int>>& before, vector<bool>& visited, vector<int>& order, int node) {

    if (visited[node] == false)
    {

        for (int j = 0; j < before[node].size(); j++) {
            DepthFirstSearch(before, visited, order, j);
        }

        order.push_back(node);
        visited[node] = true;
    }
}

void Tasks(vector<vector<int>>& before, vector<bool>& visited, vector<int>& order) {

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false)
            DepthFirstSearch(before, visited, order, i);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> before(n);
    vector<bool> visited(n, false);
    vector<int> order;
    while (m > 0) {
        m--;

        int i;
        int j;

        cin >> i >> j;

        before[j-1].push_back(i-1);
    }
    
    Tasks(before, visited, order);
    

    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    

    return 0;
}
