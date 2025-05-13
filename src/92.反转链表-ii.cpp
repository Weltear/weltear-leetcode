/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    // 两次扫描获取结果
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 当左右标识位相等时，说明无需反转
        if (left == right) return head;

        // 记录开始处的节点与扫描节点
        ListNode* left_begin = nullptr, * node = head;
        // 记录正序值
        vector<int> nums;
        // 记录当前所在节点数
        int count = 1;

        // 扫描正序值
        while (count <= right) {
            // 记录左开始节点
            if (count == left && !left_begin) left_begin = node;
            // 若进入扫描范围，添加值
            if (count >= left) nums.push_back(node->val);
            // 步进
            if (node->next) node = node->next;
            ++count;
        }

        // 重新赋值
        node = left_begin;
        for (int i = nums.size() - 1; i >= 0; --i) {
            node->val = nums[i];
            node = node->next;
        }

        return head;
    }

    /**
     * 一次遍历法
     * 穿针引线，遍历到每一个范围内节点，将节点置于反转区域最前端
     */
    ListNode* oneTime(ListNode* head, int left, int right) {
        // 设置哑节点
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;

        // 前进至反转范围前一个节点
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }

        // 将反转的节点
        ListNode* cur = pre->next;
        ListNode* next;
        for (int i = 0; i < right - left; ++i) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }

        return dummy->next;
    }
};
// @lc code=end

