// Problem: 119. Pascal's Triangle II - https://leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int nCr(int n, int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res *= (n-i);
            res /= (i+1);
        }
        return (int) res;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0; i<=rowIndex; i++){
            ans.push_back(nCr(rowIndex, i));
        }
        return ans;
    }
};


// Time Complexity: O(rowIndex^3) - We calculate the binomial coefficient for each element in the row, which takes O(rowIndex) time for each element. Since there are rowIndex+1 elements in the row, the total time complexity is O(rowIndex^3).
// Space Complexity: O(rowIndex) - We use a vector to store the result, which has a size of rowIndex+1. Therefore, the space complexity is O(rowIndex).

//Can be optimsed by using the fact that each element in the row can be calculated from the previous element using the formula: C(n, r) = C(n, r-1) * (n-r+1)/r. This way we can calculate each element in O(1) time and reduce the overall time complexity to O(rowIndex^2).