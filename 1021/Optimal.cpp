// 1021. Remove Outermost Parentheses - https://leetcode.com/problems/remove-outermost-parentheses/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    ans += c;
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                   ans += c;
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) - The space complexity is O(n) because we are creating a new string `ans` to store the result, which can be at most the same length as the input string `s`.