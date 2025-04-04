/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    // 递归算法
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 若根节点不同，返回 false
        // 空指针的情况，若两者均为空指针
        if (!p && !q) return true;
        // 两者均非空指针
        else if (p && q)  {
            // 值相等进入下一轮迭代，否则false
            if (p->val == q->val) {
                // 左右子树判断
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            }
            else return false;
        }
        // 其余情况，说明一个空一个非空，肯定是 false
        else return false;
    }
};
// @lc code=end

