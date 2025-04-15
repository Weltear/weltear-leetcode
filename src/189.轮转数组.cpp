/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 轮转 k 次即将 k % size 个的末尾元素弹出并放于开头
     * 为避免过多轮转造成的超时问题，可以采用反转法
     * 首先反转整个数组，再将前 k % size 个元素和后面的元素分别反转
     */
    void rotate(vector<int>& nums, int k) {
        // 若只有一个元素，或者轮转次数为0，直接return
        if (nums.size() == 1 || k == 0) return;

        int n = k % nums.size();

        // 整体反转
        reverse(nums.begin(), nums.end());
        // 反转前 n 个元素
        reverse(nums.begin(), nums.begin() + n - 1);
        // 反转之后的元素
        reverse(nums.begin() + n, nums.end());
    }
};
// @lc code=end

