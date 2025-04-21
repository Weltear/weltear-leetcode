/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }

    // 递归函数
    bool helper(TreeNode* left, TreeNode* right) {
        // 当左右均为空指针，返回 true
        if (!left && !right) return true;
        // 当左右均有值时，判断是否相等并继续迭代
        else if (left && right) {
            if (left->val == right->val) {
                // 当左右子树递归均相等
                if (helper(left->left, right->right) && helper(left->right, right->left)) return true;
                else return false;
            } else return false;
        }
        // 否则，根本不对称
        else return false;
    }
};
// @lc code=end

