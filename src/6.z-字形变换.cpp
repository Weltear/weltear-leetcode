/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 简单粗暴破解法
    string convert(string s, int numRows) {
        // 仅排列一行
        if (numRows == 1) return s;
        // 初始化容量为 numRows 的 string 向量
        vector<string> map(numRows);
        // 序列指针
        int ptr = 0;

        // Z 字形排列
        while (ptr < s.size()) {
            // 上至下
            for (int i = 0; i < numRows; ++i) {
                if (ptr >= s.size()) break;
                map[i].push_back(s[ptr]);
                ++ptr;
            }

            if (ptr >= s.size()) break;

            // 下至上
            for (int i = numRows - 2; i > 0; --i) {
                if (ptr >= s.size()) break;
                map[i].push_back(s[ptr]);
                ++ptr;
            }
        }

        // 输出结果
        string res = map[0];
        for (int i = 1; i < numRows; ++i) {
            res += map[i];
        }
        return res;
    }
};
// @lc code=end

