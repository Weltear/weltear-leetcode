/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    // 维护两个指针，分别为哑节点 dummy 和当前指针 now
    ListNode* deleteDuplicates(ListNode* head) {
        // 若空链表，直接返回
        if (!head) return head;
        // NOTE 对于头节点可能变化的问题，可以定义哑节点
        ListNode *dummy = new ListNode(0, head);
        ListNode *now = dummy;
        
        // 遍历链表，当 now 的后两个节点非空时
        while (now->next && now->next->next) {
            // 两者值相等，说明为重复，循环消除
            if (now->next->val == now->next->next->val) {
                // 定义重复值
                int x = now->next->val;
                // 这里不断操作 now 的 next 从而实现绕过
                while (now->next && now->next->val == x) now->next = now->next->next;
            }
            // 否则，说明只有1个，可以前进迭代
            else now = now->next;
        }

        return dummy->next;
    }
};
// @lc code=end

