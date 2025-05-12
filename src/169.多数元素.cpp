/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 最简单的思路，即使用哈希表
    int majorityElement(vector<int>& nums) {
        // 数组大小
        int n = nums.size();
        // 若大小为 1 或 2 说明仅有多数元素
        if (n == 1 || n == 2) return nums[0];
        // 出现次数哈希表
        unordered_map<int, int> map;

        // 遍历统计
        for (int i = 0; i < n; ++i) {
            // 若尚未记录，置1
            if (map.find(nums[i]) == map.end()) map[nums[i]] = 1;
            // 否则，加一并判断是否超过半数
            else {
                map[nums[i]] += 1;
                if (map[nums[i]] > n / 2) return nums[i];
            }
        }

        // 防报错
        return 0;
    }

    // BM投票算法，针对超过半数的统计具有 o(1) 的空间复杂度
    int BM_al(vector<int>& nums) {
        // 需要维护一个候选人变量与一个计数器
        int candidate = 0, count = 0;

        // 对整个数组进行遍历
        for (auto num: nums) {
            // 若当前计数器为0，将候选人更新为当前值
            if (count == 0) candidate = num;

            // 判断当前候选人与当前值的相通性，若相同，计数器+1
            if (candidate == num) ++count;
            // 否则，减一
            else --count;
        }
        
        // 最终结果为候选人
        return candidate;
    }
};
// @lc code=end

