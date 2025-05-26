/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 动态规划
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        // 动态规划列表，边界dp[0]表示空串且合法
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            // 遍历所有的分割点
            for (int j = 0; j < i; ++j) {
                // 前串与后串均在字典中
                if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    // 当前串合法
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end

