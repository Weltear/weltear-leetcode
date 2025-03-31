/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        compute(a, b, a.size() - 1, b.size() - 1, res, carry);
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }

    void compute(string &a, string &b, int a_ptr, int b_ptr, string &res, int &carry) {
        if (a_ptr < 0 && b_ptr < 0) return;
        
        int x = 0;
        int y = 0;
        if (a_ptr >= 0) x = a[a_ptr] - '0';
        if (b_ptr >= 0) y = b[b_ptr] - '0';
        int z = x + y + carry;
        if (z == 0) carry = 0;
        else if (z == 1) carry = 0;
        else if (z == 2) {
            carry = 1;
            z = 0;
        } else {
            carry = 1;
            z = 1;
        }
        res.push_back('0' + z);
        compute(a, b, a_ptr - 1, b_ptr - 1, res, carry);
    }   
};
// @lc code=end

