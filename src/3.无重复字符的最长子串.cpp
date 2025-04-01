/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        // 左右指针
        int left = 0; int right = 0;
        // 索引储存表
        unordered_map<char, int> map;
        // 结果
        int res = 0;

        for (right = 0; right < s.size(); ++right) {
            auto search = map.find(s[right]);
            // 发现存在重复值，更新左指针，更新为重复索引 + 1
            // 并且，要求查找到的索引位于左边界右侧
            // 否则，会造成旧数据复用
            if (search != map.end() && search->second >= left) left = search->second + 1;
            // 更新map
            map[s[right]] = right;
            // 更新res
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end

