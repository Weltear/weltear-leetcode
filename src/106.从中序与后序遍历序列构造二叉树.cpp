/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int post_idx;
    unordered_map<int, int> map;
public:
    TreeNode *helper(int in_left, int in_right, vector<int> &inorder, vector<int> &postorder) {
        // 若没有节点创造二叉树，结束
        if (in_left > in_right) return nullptr;

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);

        // 根据 root 所在位置分为两个子树
        int index = map[root_val];

        // 下标减一
        // 后序遍历的逆相当于先右后左
        --post_idx;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }

    // 利用后序遍历尾元素为根节点的特性，递归暴力解法
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立 （元素，下标）键值对哈希表
        // 通过 postorder 倒序值映射至中序遍历的位置
        // 中序遍历中的根节点位置，右侧为右子节点，左侧为左子节点
        // 通过这种方法即可开始递归
        int idx = 0;
        for (auto &val: inorder) {
            map[val] = idx++;
        }

        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end

