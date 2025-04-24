/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    // 二分法求取
    int mySqrt(int x) {
        // 若 x 为0或1直接返回
        if (x == 0 || x == 1) return x;

        // 定义边界
        int left = 0;
        int right = x;
        
        while (1) {
            // 获得中点,通过适当操作防溢出
            int middle = left + (right - left) / 2;
            // 若中点与左边界相同，说明已经没必要
            if (middle == left) break;

            // 比较中点平方与x，更新边界
            // 防止溢出
            double p = 1.0 * middle * middle;
            if (p == x) return middle;
            else if (p > x) right = middle;
            else if (p < x) left = middle;
        }

        return left;
    }
};
// @lc code=end

