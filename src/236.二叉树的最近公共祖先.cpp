/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 若触碰到子叶，返回空指针
        if (root == nullptr) return nullptr;
        
        // 若当前节点为 p 或 q 返回当前节点指针
        // 若此时处于根节点判断，说明该树的结果就为根节点
        if (root->val == p->val || root->val == q->val) return root;

        // 深度优先搜索，先左后右
        // 结果表明当前节点的左右子树是否包含节点 p 或 q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 若左右子树分别包含两个节点，说明最深公共节点为该节点
        if (left && right) return root;
        // 若仅有一边子树包含节点，返回该子树中的上层节点指针，等待后续判断
        // 若始终仅有一边子树，说明浅层为结果
        if (left) return left;
        else return right;
    }
};
// @lc code=end

