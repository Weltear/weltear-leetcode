/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 动态规划法
    // 时间复杂度 O(n*n)，并不好
    int jump(vector<int>& nums) {
        // 存储第 i 个元素到达的最小步
        vector<int> list;
        // 到达第0个元素的步数为0，第1个元素为1
        list.push_back(0); list.push_back(1);
        // 从第三个元素开始
        for (int i = 2; i < nums.size(); ++i) {
            // 计算能够到达第i元素的元素步数最小值
            int steps = 1001;
            for (int j = 0; j < list.size(); ++j) {
                if (nums[j] + j >= i) steps = min(steps, list[j]);
                // 若该节点已无法到达，直接删除，在后续节点其也无法到达
                else list.erase(list.begin() + j);
            }
            list.push_back(steps + 1);
        }

        return list.back();
    }

    // 正向贪心算法
    int greedy(vector<int> &nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;

        for (int i = 0; i < n - 1; ++i) {
            // 当右边界大于当前索引时，开始比较更新
            if (maxPos >= i) {
                // 更新可到达的最大右边界
                maxPos = max(maxPos, i + nums[i]);
                // 当遍历至当前步可到达的最远时，更新步数与下一步最远边界
                // 通过增加end变量，减少了重复遍历
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }

        return step;
    }
};
// @lc code=end

