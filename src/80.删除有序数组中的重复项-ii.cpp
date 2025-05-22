/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 若数组大小小于等于2，直接返回
        int n = nums.size();
        if (n <= 2) return n;

        // 定义快慢指针
        // 慢指针用于生成新的数组，快指针用于处理原数组
        int slow = 2; int fast = 2;
        while (fast < n) {
            // 当且仅当快指针值与慢指针前两个值相等时
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end

