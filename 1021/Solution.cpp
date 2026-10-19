// 1021. Remove Outermost Parentheses - https://leetcode.com/problems/remove-outermost-parentheses/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        vector<int> idx;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                int el = st.top();
                st.pop();
                if(st.empty()){
                    idx.push_back(el);
                    idx.push_back(i);
                }
            }
        }
        sort(idx.rbegin(), idx.rend());
        for(int i : idx){
            s.erase(i, 1);
        }
        return s;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)