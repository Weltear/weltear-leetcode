/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    // 双指针判断子序列
    bool isSubsequence(string s, string t) {
        // 维护指针
        int s_ptr = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[s_ptr]) ++s_ptr;
        }
        if (s_ptr >= s.size()) return true;
        else return false;
    }
};
// @lc code=end

