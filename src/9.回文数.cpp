/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        // 若数字小于0或能被10整除且非零，说明必定为否
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        // 后半部分数字记录
        int reverted_number{};

        // 当记录数字大于等于剩余数字 x 时，说明已处理至一半
        while (x > reverted_number) {
            int new_number = x % 10;
            x = x / 10;
            reverted_number = reverted_number * 10 + new_number;
        }

        // 若等于，或后半部分排除掉最后一位时相等，返回真
        if (reverted_number == x || reverted_number / 10 == x) return true;
        else return false;
    }
};
// @lc code=end

