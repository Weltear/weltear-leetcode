/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        // 倒序计数
        for (int i = s.size() - 1; i >= 0; --i) {
            // 清除空格
            if (ret == 0 && s[i] == ' ') continue;
            // 计数与终止判断
            if (s[i] != ' ') ++ret;
            else break;
        }
        return ret;
    }
};
// @lc code=end

