// Problem: 48. Rotate Image - https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=i; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Time Complexity: O(n^2) - We traverse the entire matrix twice, once for transposing and once for reversing each row.
// Space Complexity: O(1) - We use constant space to perform the operations in-place