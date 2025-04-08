/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    // 单调栈队列
    stack<TreeNode*> list;
public:
    BSTIterator(TreeNode* root) {
        // 初始化 while 循环将左子树压入单调栈
        while (root) {
            list.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // 将栈顶元素弹出，同时检测弹出节点是否含有右子树，若有，入栈
        TreeNode *node = list.top(); list.pop();
        int res = node->val;
        if (node->right) {
            node = node->right;
            while (node) {
                list.push(node);
                node = node->left;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return !list.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

