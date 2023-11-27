/*
By Soliman

Solution 1:

TC: O(2n^2)
MC: O(m+n)
*/

class Solution {
public:

    void FastIO()
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    }
    
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0), cols(grid[0].size(),0);
        int counter = 0;
        for(int i = 0; i<rows.size(); i++){
            for(int j = 0; j<cols.size(); j++){
                if(grid[i][j])
                    rows[i]++,cols[j]++;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] && (rows[i]>1 || cols[j]>1))
                    counter++;
            }
        }

        return counter;
    }
};

/*

Solution 2:
TC: O()
MC: O()
*/
