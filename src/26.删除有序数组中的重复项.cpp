/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        int k = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // 若当前数字未出现，记录相对顺序
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = k;
                ++k;
            }
        }

        // 更新数组 nums
        for (auto kv: map) {
            nums[kv.second] = kv.first;
        }

        return k;
    }

    // 注意给出的数组有序，直接双指针即可
    int doublePtr(vector<int> &nums) {
        // 左右边界指针
        int left = 0, right = 0;
        // 结果
        int k = 1;

        while (right < nums.size()) {
            // 当右指针扫到与左指针不同值时，更新左边界与第 k 个元素
            if (nums[right] != nums[left]) {
                nums[k] = nums[right];
                left = right;
                ++k;
            }
            ++right;
        }

        return k;
    }
};
// @lc code=end

