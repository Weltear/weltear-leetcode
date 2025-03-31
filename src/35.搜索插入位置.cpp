/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 左边界和右边界
        int left = 0;
        int right = nums.size() - 1;
        int res;

        // 边界检查
        if (target < nums[0]) return 0;
        else if (target > nums[right]) return nums.size();

        while (1) {
            int mid = (left + right) / 2;
            // 检查左右边界是否吻合
            if (nums[mid] == target) return mid;
            else if (nums[mid + 1] == target) return mid + 1;

            // 当左右边界不吻合，且两者相差 1 时，结束循环
            if (left == right - 1) break;

            // 更新边界
            if (nums[mid] > target) right = mid;
            else left = mid;
        }
        // 插入位置为右边界
        return right;
    }

    // 标准二分查找,可避免上述繁琐的判断
    int simple(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
};
// @lc code=end

