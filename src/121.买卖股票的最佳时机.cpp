/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int res = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            // 记录当前售卖最大值
            res = max(res, prices[i] - min_price);
            // 更新最低点
            min_price = min(min_price, prices[i]);
        }

        return res;
    }
};
// @lc code=end

