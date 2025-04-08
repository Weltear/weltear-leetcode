/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
    // 创建一个哈希表存储已创建的节点，存储方式为 <旧链表节点指针，新链表节点指针>
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        // 若空链表
        if (!head) return nullptr;

        // 若该节点尚未深拷贝
        if (map.find(head) == map.end()) {
            // 创建节点
            Node *node = new Node(head->val);
            map[head] = node;
            // 分配指针
            if (head->next) node->next = copyRandomList(head->next);
            if (head->random) node->random = copyRandomList(head->random);
            return node;
        }
        // 已创建了该节点
        else {
            return map[head];
        }
    }
};
// @lc code=end

