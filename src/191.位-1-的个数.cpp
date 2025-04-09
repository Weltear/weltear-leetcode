/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    // 较为暴力的逐位运算
    int hammingWeight(int n) {
        int res;
        // 已知数字最大为31位
        for (int i = 0; i <= 31; ++i) {
            // 优化：若2的i次方比当前数字大，可终止循环
            if (n < (1 << i)) break;
            // 当数字 n 的第 i 位与 2的i次方运算非0时，说明该位为1
            if (n & (1 << i)) ++res; 
        }
        return res;
    }

    // 利用 n & (n - 1) 的结果等于将 n 的最低位1置零
    // 复杂度为 O(logn)
    int simple(int n) {
        int res;

        // 持续至 n 变为0，运算次数即为1的个数
        while (n) {
            n = n & (n - 1);
            ++res;
        }

        return res;
    }
};
// @lc code=end

