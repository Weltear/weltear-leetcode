/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 矩阵存储动态规划法，用反向递归更方便一些
    int minPathSum(vector<vector<int>>& grid) {
        // 网格高和宽
        int m = grid.size();
        int n = grid[0].size();
        // 存储当前各最小值矩阵
        vector<vector<int>> f(m, vector<int>(n, -1));
        f[0][0] = grid[0][0];

        return min_f(m - 1, n - 1, f, grid);
    }

    // 获取当前i行j列格数的最小值
    int min_f(int i, int j, vector<vector<int>>& f, const vector<vector<int>>& grid) {
        // 若最小值矩阵中存储了响应值，直接返回
        if (f[i][j] != -1) return f[i][j];

        // 获取前驱最小值
        int f_left = 40001;
        if (i > 0) f_left = min_f(i - 1, j, f, grid);

        int f_up = 40001;
        if (j > 0) f_up = min_f(i, j - 1, f, grid);

        // 计算当前最小值并插入
        int val = min(f_left, f_up) + grid[i][j];
        f[i][j] = val;
        return val;
    }
};
// @lc code=end

