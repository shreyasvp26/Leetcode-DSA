// 69. Sqrt(x) - https://leetcode.com/problems/sqrtx/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 1, h = x/2;
        int ans = x;
        while(l<=h){
            int m = l + (h-l)/2;
            if(m <= x/m){
                ans = m;
                l = m+1;
            }
            else h = m-1;
        }
        return ans;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)