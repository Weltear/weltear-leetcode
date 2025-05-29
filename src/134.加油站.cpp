/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 该问题可转化为，将加油表与消耗表作差获得盈余表
     * 若要满足要求需要两个条件：
     * 1.盈余表总和>=0
     * 2.找到盈余表的阶段性总和非零的起始点
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 算法维护三个值：盈余总和、起始位置、起始点开始的总和
        int sum = 0;
        int start = 0;
        int partial_sum = 0;
        // 遍历求解
        for (int i = 0; i < gas.size(); ++i) {
            // 盈余
            int gain = gas[i] - cost[i];
            sum += gain;
            partial_sum += gain;
            // 若阶段性盈余小于0，说明当前的起始点错误，更新起始点
            if (partial_sum < 0) {
                partial_sum = 0;
                start = i + 1;
            }
        }
        // 若全程盈余小于等于0，必定无法完成
        if (sum < 0) return -1;
        else return start;
    }
};
// @lc code=end

