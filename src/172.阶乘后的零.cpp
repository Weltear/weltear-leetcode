/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    /**
     * 考虑到每有一个2和一个5配对，会产生一个0
     * 但是阶乘中可以分解出很多2，因此只需要考虑能分解出多少个5即可
     */
    int trailingZeroes(int n) {
        // 若n为0，直接返回
        if (n == 0) return 0;
        // 5 的个数
        int count = 0;
        // 5 25 125 625 ...
        int p = 5;
        while (p <= n) {
            count += n / p;
            p *= 5;
        }
        return count;
    }
};
// @lc code=end

