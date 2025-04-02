/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> last_list;
    vector<int> now_list;
    int minimumTotal(vector<vector<int>>& triangle) {
        for (auto row: triangle) {
            // 第一轮循环，直接添加
            if (last_list.empty()) last_list.push_back(row[0]);
            else {
                now_list.clear();
                for (int j = 0; j < row.size(); ++j) {
                    if (j == 0) now_list.push_back(last_list[j] + row[j]);
                    else if (j == row.size() - 1) now_list.push_back(last_list[j - 1] + row[j]);
                    else now_list.push_back(min(last_list[j], last_list[j - 1]) + row[j]);
                }
                last_list = now_list;
            }
        }
        return *min_element(last_list.begin(), last_list.end());
    }
};
// @lc code=end

