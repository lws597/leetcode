/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> flags;
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int depth, vector<int>& val) {
        if (depth >= nums.size()) {
            ans.push_back(val);
            return ;
        }
        for (int num : nums) {
            if (flags[num] > 0) continue;
            flags[num]++;
            val.push_back(num);
            backtrack(nums, depth + 1, val);
            flags[num]--;
            val.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> val;
        backtrack(nums, 0, val);
        return ans;
    }
};
// @lc code=end

