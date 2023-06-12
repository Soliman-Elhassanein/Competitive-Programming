class Solution {
public:
    int triangularSum(vector<int>& nums) {

    vector<int> newnums= nums;

    while (nums.size() != 1) {
        newnums.clear();
        for (int i = 0; i < nums.size()-1; i++) {
            newnums.push_back((nums[i] + nums[i + 1] )%10);
        }
        nums = newnums;
    }

    return newnums[0];
}
};
