/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // 递归原地修改方法
    void flatten(TreeNode* root) {
        // 当前节点为空指针，直接返回
        if (!root) return;

        // 展开左子树
        flatten(root->left);
        // 展开右子树
        flatten(root->right);

        // 存在左子树，将左子树拼接至右子树
        if (root->left) {
            // 左子树起始点
            TreeNode* left_start = root->left;
            // 左子树结尾点
            TreeNode* left_end = root->left;
            while (left_end->right) left_end = left_end->right;

            // 存在右子树，拼接
            if (root->right) {
                // 右子树起始点
                TreeNode* right = root->right;
                // 拼接
                root->right = left_start;
                left_end->right = right;
            }
            // 不存在右子树，直接加上
            else root->right = left_start;

            // 将原左子树置空
            root->left = nullptr;
        }
    }
};
// @lc code=end

