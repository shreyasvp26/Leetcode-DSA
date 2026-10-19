// 1614. Maximum Nesting Depth of the Parentheses - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') cnt += 1;
            else if (s[i] == ')') cnt -= 1;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)