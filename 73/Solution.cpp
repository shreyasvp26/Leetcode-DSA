// 73. Set Matrix Zeroes - https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> zeros;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto it : zeros){
            int i = it.first;
            for(int j=0; j<m; j++){
                matrix[i][j] = 0;
            }
            int j = it.second;
            for(int k=0; k<n; k++){
                matrix[k][j] = 0;
            }
        }
    }
};

// Time Complexity: O(n*m) - We traverse the entire matrix twice, once to find the zeros and once to set the rows and columns to zero.
// Space Complexity: O(k) - We use extra space to store the positions of zeros, where k is the number of zeros in the matrix.