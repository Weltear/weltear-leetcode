/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 建立最后一次出现的位置哈希表
        unordered_map<int, int> map;
        // 对数组遍历一次
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) map[nums[i]] = i;
            else {
                if (i - map[nums[i]] <= k) return true;
                else map[nums[i]] = i;
            } 
        }
        return false;
    }
};
// @lc code=end

