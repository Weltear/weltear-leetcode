/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 罗马数字哈希表
    unordered_map<char, int> map {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}  
    };
    int romanToInt(string s) {
        int ret = 0;
        int i = 0;

        // 遍历处理
        for (i = 0; i < s.size() - 1; ++i) {
            // 若遇到可能存在特殊情况的数字
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                ret += map[s[i + 1]] - map['I'];
                ++i;
            }
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                ret += map[s[i + 1]] - map['X'];
                ++i;
            }
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                ret += map[s[i + 1]] - map['C'];
                ++i;
            }
            else ret += map[s[i]];
        }
        if (i == s.size() - 1) ret += map[*(s.end() - 1)];
        return ret;
    }
};
// @lc code=end

