/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

using namespace std;

class Solution {
public:
    // 哈希表法
    bool wordPattern(string pattern, string s) {
        // 新建字母-单词对照表
        unordered_map<char, string> map;
        // 单词使用表
        unordered_set<string> list;
        // 字母序列指示
        int ptr = 0;
        // 单词存储
        string word;

        for (int i = 0; i <= s.size(); ++i) {
            // 当扫描至空格时，开始判断
            if (isspace(s[i]) || i == s.size()) {
                // 判断是否包含
                if (map.find(pattern[ptr]) == map.end()) {
                    // 判断单词是否已经使用
                    if (list.count(word)) return false;
                    else {
                        map[pattern[ptr]] = word;
                        list.insert(word);
                    }
                }
                else {
                    if (map[pattern[ptr]] != word) return false;
                }
                // 清空单词，步进
                word.clear();
                ++ptr;
            } else {
                word.push_back(s[i]);
            }
        }

        // 若此时还有空余字母
        if (ptr != pattern.size()) return false;
        else return true;
    }
};
// @lc code=end

