// 540. Single Element in a Sorted Array - https://leetcode.com/problems/single-element-in-a-sorted-array/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l<h){
            int m = l + (h-l)/2;
            if(m&1) m--;
            if(nums[m]==nums[m+1]) l = m+2;
            else h = m-1;
        }
        return nums[l];
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)