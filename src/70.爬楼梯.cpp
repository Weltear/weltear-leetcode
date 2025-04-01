/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> map{};

    // 考虑第十级台阶，其方法为从9跨1或者从8跨2，即f(10) = f(9) + f(8)
    // 递推公式 f(n) = f(n-1) + f(n-2)
    // 递归中会出现重复计算，考虑用哈希表存储历史值
    // 此方法时间复杂度 O(n) 但有存储开销
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else {
            // 历史表中是否已计算该值
            auto val = map.find(n);
            if (val != map.end()) return val->second;
            else {
                int res = climbStairs(n - 1) + climbStairs(n - 2);
                map[n] = res;
                return res;
            }
        }
    }

    // 动态规划方法，与递归法自顶向下相反，为自下向顶
    // f(n) = f(n-1) + f(n-2) 为状态转移方程
    // f(1) 与 f(2) 为问题边界
    // f(n-1) + f(n-2) 为 f(n) 的最优子结构
    // 之间的重复计算称为重复子问题
    // 动态规划方法避免了存储开销
    int climbStairs_DP(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else {
            int n_1 = 2;
            int n_2 = 1;
            int res{};
            for (int i = 3; i <= n; ++i) {
                res = n_1 + n_2;
                n_2 = n_1;
                n_1 = res;
            }
            return res;
        }
    }
};
// @lc code=end

