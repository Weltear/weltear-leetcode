/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // 新建向量变量作为存储栈
        vector<string> stack{};
        // 初始指向为 1，跳过第一个/
        int ptr = 1;
        // 存储文件名
        string folder{};
        
        for (ptr = 1; ptr <= path.size(); ++ptr) {
            // 扫描至 '/' 或 ptr 结束扫描时，进行文件名处理
            if (path[ptr] == '/' || ptr == path.size()) {
                // folder中含有文件名
                if (!folder.empty()) {
                    // 为'..'且 stack 非空，删除上一个
                    if (folder == ".." && !stack.empty()) stack.pop_back();
                    // 为'.'跳过
                    else if (folder == ".") {}
                    // 为正常文件名
                    else if (folder != "..") {
                        stack.push_back(folder);
                    }
                    folder.clear();
                }
                // folder 中未含文件名，模拟多重 '/'
                else continue;
            }
            // 扫描至非 '/'
            else folder.push_back(path[ptr]);
        }

        // 构造新路径
        string res = "/";
        for (auto f: stack) res += f + '/';
        if (*(res.end() - 1) == '/' && res.size() != 1) res.pop_back();
        return res;
    }
};
// @lc code=end

