/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        // 维护两个26数组
        int a[26] = {0};
        int b[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            a[s[i] - 'a'] += 1;
            b[t[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
// @lc code=end

