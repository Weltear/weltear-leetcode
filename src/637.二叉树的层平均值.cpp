/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

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
    vector<double> averageOfLevels(TreeNode* root) {
        // 存储结果的向量
        vector<double> res;
        // 广度优先搜索，存储每一层节点队列
        queue<TreeNode*> q;
        // 队列启动
        q.push(root);

        // 遍历至队列为空时
        while (q.size()) {
            res.push_back(search(q));
        }

        return res;
    }

    // 广度优先搜索，进入下一层，并返回当前层的平均值
    double search(queue<TreeNode*>& q) {
        double res = 0;
        // 当前层节点数量
        int n = q.size();

        // 前出后进
        for (int i = 0; i < n; ++i) {
            // 获取队列前端节点
            TreeNode* node = q.front();
            // 若存在左右节点，入栈
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            // 当前节点弹出
            q.pop();
            // 纳入统计值
            res += node->val;
        }

        return res / n;
    }
};
// @lc code=end

