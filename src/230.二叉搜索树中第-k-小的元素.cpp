/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // 全局计数
    int count = 0;
    // 中序遍历递归求解
    int kthSmallest(TreeNode* root, int k) {
        // 检查当前节点是否为叶子节点
        if (!root->left && !root->right) {
            ++count;
            if (count == k) return root->val;
            else return -1;
        }

        // 中序遍历
        if (root->left) {
            int left_ret = kthSmallest(root->left, k);
            if (left_ret != -1) return left_ret;
        }
        ++count;
        if (count == k) return root->val;
        if (root->right) {
            int right_ret = kthSmallest(root->right, k);
            if (right_ret != -1) return right_ret;
        }

        return -1;
    }
};
// @lc code=end

