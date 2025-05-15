/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 哈希表法，将每个单词排序后对比
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        // 遍历整个字符串数组
        for (auto& word: strs) {
            // 创建排序后的单词副本
            string word_sorted = word;
            sort(word_sorted.begin(), word_sorted.end());

            // 在哈希表中查找添加
            if (map.find(word_sorted) == map.end()) {
                // 创建新的键值对
                map[word_sorted] = vector<string>{word};
            } else {
                // 直接添加
                map[word_sorted].push_back(word);
            }
        }

        // 形成结果
        vector<vector<string>> res;
        for (auto& pair: map) res.push_back(pair.second);
        return res;
    }
};
// @lc code=end

