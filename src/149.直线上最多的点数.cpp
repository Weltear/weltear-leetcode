/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // 最大公约数
    int gcd(int a, int b) {
        // NOTE 求最大公约数的算法：辗转相除法
        return b? gcd(b, a % b) : a;
    }

    // 比较直观且简单的方法：将向量中每个点固定并统计与其他点的斜率
    // 需要注意，由于 float 类型的精度问题，记录斜率采用字符串加最大公约数的方法
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        // 若点小于等于2，说明必为n
        if (n <= 2) return n;

        int ret = 0;

        for (int i = 0; i < n; ++i) {
            // 优化：只需考虑编号大于 i 的点，小于的点在之前已经考虑过
            // 优化：当至多找到 n - i 个共线，若之前的最大值 ret 大于，则可以停止，不可能找到更大值
            // 优化：当直线包含超过半数点时，肯定为该直线
            if (ret >= n - i || ret > n / 2) break;

            unordered_map<string, int> map;
            for (int j = i + 1; j < n; ++j) {
                // 差分值
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                // 特殊值采用 “1/0” 与 “0/1”的方式
                if (dx == 0) dy = 1;
                else if (dy == 0) dx = 1;
                // 消除符号差异，保持右到左 即 dx > 0
                else {
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                }
                map[to_string(dy) + "/" + to_string(dx)]++;
            }

            int maxn = 0;
            // NOTE Cpp的模式匹配
            for (auto &[_, num]: map) maxn = max(maxn, num + 1);
            ret = max(ret, maxn);
        }
        return ret;
    }
};
// @lc code=end

