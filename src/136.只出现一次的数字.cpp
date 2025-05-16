/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 哈希表法
    int singleNumber(vector<int>& nums) {
        // 建立哈希表
        unordered_map<int, int> map;

        // 遍历数组
        for (auto num: nums) {
            if (map.find(num) == map.end()) map[num] = 1;
            // 若已经存在，说明：1.该值不是结果 2.该值以后不会出现
            else map.erase(num);
        }

        // map中仅存唯一一个键值对
        return (*map.begin()).first;
    }

    // 位运算法，空间复杂度为常量，采用异或运算
    int XOR(vector<int>& nums) {
        int ret = 0;
        for (auto num: nums) ret ^= num;
        return ret;
    }
};
// @lc code=end

