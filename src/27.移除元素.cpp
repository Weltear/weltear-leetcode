/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (auto num: nums) {
            if (num != val) {
                nums[k] = num;
                ++k;
            }
        }

        return k;
    }
};
// @lc code=end

