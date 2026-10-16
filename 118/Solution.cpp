// Problem: 118. Pascal's Triangle - https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int nCr (int n, int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res *= (n-i);
            res /= (i+1);
        }
        return (int) res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){
            vector<int> level;
            for(int r = 0; r<=i ; r++){
                level.push_back(nCr(i, r));
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// Time Complexity: O(numRows^3) - We calculate the binomial coefficient for each element in the triangle, which takes O(numRows) time for each element. Since there are numRows*(numRows+1)/2 elements in the triangle, the total time complexity is O(numRows^3).
// Space Complexity: O(numRows^2) - We use a 2D vector to store the result, which has a size of numRows*(numRows+1)/2. Therefore, the space complexity is O(numRows^2).

//Can be optimsed by using the fact that each element in the row can be calculated from the previous element using the formula: C(n, r) = C(n, r-1) * (n-r+1)/r. This way we can calculate each element in O(1) time and reduce the overall time complexity to O(rowIndex^2).