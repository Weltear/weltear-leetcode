/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 建立数字栈
        stack<int> nums;

        // 扫描字符串数组
        for (int i = 0; i < tokens.size(); ++i) {
            // 扫描到算符
            if (tokens[i] == "+" || tokens[i] == "-" || 
                tokens[i] == "*" || tokens[i] == "/") compute(nums, tokens[i]);
            // 扫描到数字，直接压栈
            else nums.push(parse(tokens[i]));
        }

        return nums.top();
    }

    // 解析数字
    int parse(const string& tokens) {
        int n = tokens.size();
        int res = 0;
        // 是否负数 flag
        bool flag = false;

        for (int i = 0; i < n; ++i) {
            // 是否为负号
            if (tokens[i] == '-') flag = true;
            else {
                // 解析当前数字
                int num = tokens[i] - '0';
                // 叠加数字
                res = res * 10 + num;
            }
            
        }

        if (flag) return -res;
        else return res;
    }

    // 计算
    void compute(stack<int>& nums, const string& token) {
        // 出栈两个数字
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();

        // 计算结果
        if (token == "+") nums.push(a + b);
        else if (token == "-") nums.push(a - b);
        else if (token == "*") nums.push(a * b);
        else nums.push(a / b);
    }
};
// @lc code=end

