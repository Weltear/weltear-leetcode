/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m_board = board;
        m_rowCnt = board.size();
        m_colCnt = board[0].size();
        for (int i = 0; i < m_rowCnt; ++i) {
            for (int j = 0; j < m_colCnt; ++j) {
                std::vector<std::vector<bool>> visited(m_rowCnt, std::vector<bool>(m_colCnt, false));
                if (dfs(visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<bool>>& visited, int x, int y, const string& word, int curr) {
        if (curr >= word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= m_rowCnt || y >= m_colCnt) {
            return false;
        }
        if (visited[x][y] || m_board[x][y] != word[curr]) {
            return false;
        }
        visited[x][y] = true;
        bool found = dfs(visited, x, y - 1, word, curr + 1)
            || dfs(visited, x, y + 1, word, curr + 1)
            || dfs(visited, x - 1, y, word, curr + 1)
            || dfs(visited, x + 1, y, word, curr + 1);
        visited[x][y] = false;
        return found;
    }
private:
    vector<vector<char>> m_board;
    int m_rowCnt;
    int m_colCnt;
};
// @lc code=end

