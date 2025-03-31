/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto another = map.find(diff);
            if (another != map.end()) return vector<int> {another->second, i};
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

