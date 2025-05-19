/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    /* 建立一个n大小的数组，第k个元素的含义为：引用不少于k的论文数量，当k==nums[k]时，结束 */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> nums(n + 1);

        // 遍历所有引用次数
        for (auto k: citations) {
            if (k > n) k = n;
            // 将nums中所有小于等于k索引的元素加起来
            for (int i = k; i >= 0; --i) {
                nums[i] += 1;
            }
        }
        
        // 寻找合适值，寻找最大值的倒序
        for (int i = n; i >= 0; --i) if (nums[i] >= i) return i;
        return 0;
    }
};
// @lc code=end

