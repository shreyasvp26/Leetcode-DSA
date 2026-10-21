// 240. Search a 2D Matrix II - https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};

// Time Complexity: O(n+m) where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity: O(1) since we are using constant space.