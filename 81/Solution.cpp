// 81. Search in Rotated Sorted Array II - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]==target) return true;
            if (nums[l] == nums[m] && nums[m] == nums[h]) {
                l++;
                h--;
            }
            else if(nums[m] >= nums[l]){
                if(nums[m]>target && target >= nums[l]) h = m-1;
                else l = m+1;
            }
            else{
                if(nums[m] < target && target<=nums[h]) l = m+1;
                else h = m-1;
            }
        }
        return false;
    }
};

// Time Complexity: O(log n) in average case, O(n) in worst case (when all elements are the same)
// Space Complexity: O(1)