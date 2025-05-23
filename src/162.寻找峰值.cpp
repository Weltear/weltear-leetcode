/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 二分查找——找阶段性坡顶
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // 若只有一个元素，直接返回
        if (n == 1) return 0;
        // 二分查找左右边界
        int left = 0;
        int right = n - 1; 
        int mid = (left + right) / 2;

        while (mid != left) {
            // 判断是否为坡顶，若非坡顶，找到上升方向
            if (mid == 0) {
                if (nums[mid] > nums[1]) return mid;
                else left = mid;
            } else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1]) return mid;
                else right = mid;
            } else {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
                // 找到上升方向
                if (nums[mid] < nums[mid - 1]) right = mid;
                else if (nums[mid] < nums[mid + 1]) left = mid;
            }
            mid = (left + right) / 2;
        }
        // 若停止循环，返回较大值
        if (nums[left] > nums[right]) return left;
        else return right;
    }
};
// @lc code=end

