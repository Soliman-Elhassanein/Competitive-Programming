/*
By Soliman Elhassanein

18-Nov-2023

Solution 1
TC: O(n)
MC:O(1)


*/


class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for(int i = 2; i<n+1; i++){
            ans = (ans + k) % i;
        }

        return ans + 1;
    }

};



/*
Solution 2
TC: O(n)
MC: O(n)
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;

        for (int i = 1; i < n + 1; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};




