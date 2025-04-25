/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }

    // 递归计算
    bool helper(TreeNode* node, const int& targetSum, int sum) {
        if (!node) return false;
        // 若当前为叶子节点，判断总和是否满足要求
        if (!node->left && !node->right) {
            sum = sum + node->val;
            if (sum == targetSum) return true;
            else return false;
        }
        // 若不是叶子节点，递归处理子树
        else {
            bool left = false;
            bool right = false;
            if (node->left) left = helper(node->left, targetSum, sum + node->val);
            if (node->right) right = helper(node->right, targetSum, sum + node->val);
            return left || right;
        }
    }
};
// @lc code=end

