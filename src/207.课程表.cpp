/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 创建入度表，初始化为全零
        vector<int> in_degree(numCourses, 0);
        // 创建后续节点哈希表
        unordered_map<int, vector<int>> map;

        // 遍历关联表，记录关联关系
        for (auto item: prerequisites) {
            // 关联对的第一项为入度+1项
            in_degree[item[0]] += 1;
            // 记录后续节点
            map[item[1]].push_back(item[0]);
        }

        // 创建已选课队列
        queue<int> q;
        // 已选课程数量
        int count = 0;
        // 将所有初始入度为 0 的课程加入队列
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) { 
                q.push(i);
                ++count;
            }
        }

        // 开始拓扑排序
        while (q.size()) {
            // 取出前面一个入度0课程，将后继所有课程入度-1
            int course = q.front(); q.pop();
            for (auto next: map[course]) {
                in_degree[next] -= 1;
                // 若后继入度降低为0，加入队列
                if (in_degree[next] == 0) { 
                    q.push(next);
                    ++count;
                }
            }
        }
        
        // 若选择的课与总课程数相等，说明为有向无环图
        return count == numCourses;
    }
};
// @lc code=end

