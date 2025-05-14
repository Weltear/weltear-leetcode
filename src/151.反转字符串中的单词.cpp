/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 非原地修改法，创建vector存储扫描结果
    string reverseWords(string s) {
        // 单词存储向量
        vector<string> words;
        // 临时单词存储变量
        string word;

        // 扫描s字符串
        for (int i = 0; i < s.size(); ++i) {
            // 若为空格
            if (s[i] == ' ') {
                // 若临时存储变量中有值，添加至向量中
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
                // 跳过
                continue;
            }
            // 将字符添加至临时存储变量中
            word.push_back(s[i]);
        }

        // 倒序形成结果
        string res;
        for (int i = words.size() - 1; i >= 0; --i) {
            res += words[i];
            if (i != 0) res += ' ';
        }

        return res;
    }

    // 双指针法
    string doublePtr(string s) {
        // 第一个指针，指向字符串尾部
        int left = s.size() - 1;
        // 结果字符串
        string res;
        // 去除尾部空格
        while (s[left] == ' ' && left > 0) --left;
        // 另一个指针
        int right = left;
        // 遍历处理
        while (left >= 0) {
            // 截取一个单词的长度
            while (left >= 0 && s[left] != ' ') --left;
            res += s.substr(left + 1, right - left) + " ";
            // 消去空格
            while (left >= 0 && s[left] == ' ') --left;
            right = left;
        }
        // 消除最后一位空格
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end

