/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        if (n <= 0) return res;
        helper("", n, n, res);
        return res;
    }

    /**
     * \brief 递归生成结果
     * \param str 当前的空格字符串
     * \param left 剩余可用左空格数量
     * \param right 剩余可用右空格数量
     */
    void helper(string str, int left, int right, vector<string>& res) {
        // 当左右空格耗尽，当前结果添加入向量中
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }

        // 剩余右括号比左括号多或相等时，可以添加左括号或右括号
        if (right >= left) {
            if (left >= 1) helper(str + "(", left - 1, right, res);
            if (right >= 1) helper(str + ")", left, right - 1, res);
        }
    }
};
// @lc code=end

