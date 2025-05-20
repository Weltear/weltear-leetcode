/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 若仅有一个步，说明必可以
        if (nums.size() == 1) return true;
        // 存储一个变量为上一步所在位置
        int pre = -1;
        // 存储一个变量为当前所在位置
        int cur = 0;

        // 能够前进时
        while (pre != cur) {
            // 若当前所在位置移动力为0，被卡死
            if (nums[cur] == 0) return false;
            // 判断当前位置能否到达终点
            if (cur + nums[cur] >= nums.size() - 1) return true;

            int jump = 1;
            int total = jump + nums[cur + jump];
            // 遍历所有能够移动的步数，选取能够跳跃的最大步
            for (int i = 2; i <= nums[cur]; ++i) {
                if (i + nums[cur + i] > total) {
                    jump = i;
                    total = i + nums[cur + i];
                }
            }
            // 跳跃
            pre = cur;
            cur = cur + jump;
        }

        // 默认返回false
        return false;
    }

    // 最远可达位置法
    bool farthest(vector<int> &nums) {
        // 维护一个最远可到达的位置
        int farthest = 0;
        int n = nums.size();

        // 遍历每个节点，判断最远可达位置是否大于当前位置
        for (int i = 0; i < n; ++i) {
            if (i <= farthest) farthest = max(i + nums[i], farthest);
        }

        return farthest >= n - 1;
    }
};
// @lc code=end

