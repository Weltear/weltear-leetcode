/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // 前缀积与后缀积法
    // 维护两个数组，分别为数组元素所在位置之前所有元素的积与后方元素的积
    // 求解直接取对应索引做积即可
    vector<int> productExceptSelf(vector<int>& nums) {
        // 前缀积
        vector<int> pre;
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur *= nums[i];
            pre.push_back(cur);
        }
        // 后缀积
        vector<int> ret(nums.size(), 1);
        cur = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            ret[i] = cur * pre[i - 1];
            cur *= nums[i];
        }
        ret[0] = cur;
        return ret;
    }
};
// @lc code=end

