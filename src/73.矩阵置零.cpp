/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 两个哈希集合记录清零的行列
        unordered_set<int> row;
        unordered_set<int> column;

        // 遍历寻找0元素位置
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }

        // 修改矩阵值
        for (auto i = row.begin(); i != row.end(); ++i) {
            matrix[*i] = vector<int> (matrix[*i].size(), 0);
        }
        for (auto i = column.begin(); i != column.end(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[j][*i] = 0;
            }
        }
    }
};
// @lc code=end

