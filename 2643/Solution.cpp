// 2643. Rows with maximum ones - https://leetcode.com/problems/row-with-maximum-ones/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = 0, max_index = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j]) cnt++;
            }
            if(cnt > maxi){
                maxi = cnt;
                max_index = i;
            }
        }
        return {max_index, maxi};
    }
};

// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix. We iterate through each element of the matrix to count the number of ones in each row.
// Space Complexity: O(1) as we are using a constant amount of extra space for variables maxi, max_index, cnt, n, and m. The output vector is of fixed size 2, which does not depend on the input size.