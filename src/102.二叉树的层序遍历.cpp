/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

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
    // 队列解决广度优先遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        // 若为空树，直接返回
        if (!root) return ret;

        // 创建队列，开始遍历
        queue<TreeNode *> q; q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> cur;
            // 遍历队列中的节点，生成层序遍历并添加下一层节点
            for (int i = 0; i < n; ++i) {
                TreeNode *front = q.front(); q.pop();
                cur.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            ret.push_back(cur);
        }

        return ret;
    }
};
// @lc code=end

