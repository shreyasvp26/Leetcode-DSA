// Problem: 54. Spiral Matrix - https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n-1;
        int left = 0, right = m-1;
        while(top <= bottom && left <= right){
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

// Time Complexity: O(n*m) - We traverse the entire matrix once to get the spiral order.
// Space Complexity: O(1) - We use constant space to store the result.

// We add conditions to last 2 loops to check if the top and bottom pointers have crossed each other or if the left and right pointers have crossed each other. 
//This is important because in some cases, we may have already traversed the entire matrix and we don't want to add any more elements to the result vector.