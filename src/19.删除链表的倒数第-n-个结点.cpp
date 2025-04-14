/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(nullptr) {}
};

class Solution {
public:
    // 快慢节点法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 若只有一个头节点，直接返回 nullptr
        if (!head->next) return nullptr;

        // 定义快慢节点
        ListNode *fast = head;
        ListNode *slow = new ListNode(-1, head);

        // 倒数第 n 个节点，即慢指针相对快指针慢 n - 1 个节点，使用哑节点
        for (int i = 0; i < n - 1; ++i) fast = fast->next;

        // 两者同时步进，直至快节点到达尾节点
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // 跳过慢节点的下一个节点
        slow->next = slow->next->next;

        // 若慢节点的值为-1，说明被跳过的是头节点
        if (slow->val == -1) return slow->next;
        // 否则，返回head
        else return head;
    }
};
// @lc code=end

