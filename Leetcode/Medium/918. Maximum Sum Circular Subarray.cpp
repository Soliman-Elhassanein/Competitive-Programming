/*
By: Soliman Elhassanein

TC: O(n)
MC: O(1)

*/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, globMax = nums[0], globMin = nums[0], curMax = 0, curMin = 0;

        for (auto& i : nums) {
            total += i;
            curMax = max(curMax + i, i);
            globMax = max(curMax, globMax);
            curMin = min(curMin + i, i);
            globMin = min(curMin, globMin);
        }


        return (globMax > 0 ? max(globMax, total - globMin) : globMax);
    }
};
