// 74. Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = n*m-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(mat[mid/m][mid%m] == target) return true;
            else if(mat[mid/m][mid%m] > target) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
};

// Time Complexity: O(log(n*m)) where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity: O(1) since we are using constant space.