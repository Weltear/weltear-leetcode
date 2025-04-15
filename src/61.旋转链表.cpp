/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 快慢节点法
     * 第一次遍历找到尾节点，将链表变为循环链表
     * 之后头尾节点同时移动 k % size 个位置后打断
     */
    ListNode* rotateRight(ListNode* head, int k) {
        // 为空链表或只有一个节点，直接返回头节点
        if (!head || !head->next) return head;
        
        // 找到头尾节点
        int size = 1;
        ListNode* end = head;
        while (end->next) {
            end = end->next;
            ++size;
        }
        // 连接为循环节点
        end->next = head;

        // 同时向右步进 k % size
        for (int i = 0; i < size - k % size; ++i) {
            head = head->next;
            end = end->next;
        }
        // 打断链表，返回
        end->next = nullptr;
        return head;
    }
};
// @lc code=end

