/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 若仅有一个字符且两者相等，直接返回
        if (s.size() == 1 && s == t) return true;

        // 构造映射表和已用字符
        unordered_map<char, char> st_map;
        unordered_map<char, char> ts_map;

        // 遍历
        for (int i = 0; i < s.size(); ++i) {
            // 扫描到新字符
            if (st_map.find(s[i]) == st_map.end()) {
                // 若对应字符已经被映射
                if (ts_map.find(t[i]) != ts_map.end()) return false;
                // 否则，添加映射
                st_map[s[i]] = t[i];
                ts_map[t[i]] = s[i];
            }
            // 已映射字符，调查是否映射成立
            else {
                if (st_map[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};
// @lc code=end

