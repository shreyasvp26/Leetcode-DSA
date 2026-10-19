// 35. Search Insert Position - https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int pos = nums.size();
        while (l <= h) {
            int m = l + (h-l)/2;
            if(nums[m] > target){
                pos = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        if(pos-1 >=0 && nums[pos-1]==target) return pos-1;
        return pos;
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(1)