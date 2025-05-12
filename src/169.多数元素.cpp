/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 最简单的思路，即使用哈希表
    int majorityElement(vector<int>& nums) {
        // 数组大小
        int n = nums.size();
        // 若大小为 1 或 2 说明仅有多数元素
        if (n == 1 || n == 2) return nums[0];
        // 出现次数哈希表
        unordered_map<int, int> map;

        // 遍历统计
        for (int i = 0; i < n; ++i) {
            // 若尚未记录，置1
            if (map.find(nums[i]) == map.end()) map[nums[i]] = 1;
            // 否则，加一并判断是否超过半数
            else {
                map[nums[i]] += 1;
                if (map[nums[i]] > n / 2) return nums[i];
            }
        }

        // 防报错
        return 0;
    }
};
// @lc code=end

