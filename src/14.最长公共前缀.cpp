/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 纵向扫描
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int ptr = 0;
        int length = 0;

        while (true) {
            // 当指针为0时，说明开始了新一轮扫描，长度+1
            if (ptr == 0) {
                // 若长度已经超出第一个单词长度，打断
                if (++length > strs[0].size()) break;
                res.push_back(strs[ptr][length - 1]);
            }
            // 其余情况，扫描是否相等
            else {
                // 相等，继续循环，否则打断
                if (res.back() != strs[ptr][length - 1]) {
                    res.pop_back();
                    break;
                }
            }

            // 指针加一，若超限返回0
            if (++ptr == strs.size()) ptr = 0;
        }

        return res;
    }
};
// @lc code=end

