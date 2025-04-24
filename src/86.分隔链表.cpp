/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    /**
     * 维护几个节点：
     * 记录头节点
     * 记录遍历节点
     * 记录前半链表尾部
     * 记录后半链表头部和尾部
     */
    ListNode* partition(ListNode* head, int x) {
        // 若头节点为空或无后继节点，直接返回
        if (!head || !head->next) return head;

        // 初始化所需指针
        ListNode* first_begin = nullptr;
        ListNode* first_end = nullptr;
        ListNode* second_begin = nullptr;
        ListNode* second_end = nullptr;
        ListNode* node = head;

        // 遍历所有节点
        while (node) {
            if (node->val >= x) {
                if (!second_begin) {
                    second_begin = node;
                    second_end = node;
                }
                else {
                    second_end->next = node;
                    second_end = second_end->next;
                }
            }
            else {
                if (!first_begin) {
                    first_begin = node;
                    first_end = node;
                }
                else {
                    first_end->next = node;
                    first_end = first_end->next;
                }
            }
            node = node->next;
        }

        // 进行初步处理，将第二部分的尾节点指向空
        if (second_end) second_end->next = nullptr;
        // 第一部分存在
        if (first_begin) {
            first_end->next = second_begin;
            return first_begin;
        }
        // 第一部分不存在
        else return second_begin;
    }
};
// @lc code=end

