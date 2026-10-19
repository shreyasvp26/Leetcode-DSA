// 33. Search in Rotated Sorted Array - https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m] == target) return m;
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) h = m - 1;
                else l = m + 1;
            }
            else {
                if (nums[m] < target && target <= nums[h]) l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};

// Time Complexity: O(log n) - The algorithm performs a binary search, which divides the search space in half with each iteration, leading to logarithmic time complexity.
// Space Complexity: O(1) - The algorithm uses a constant amount of extra space, as it only requires a few variables for the indices and does not use any additional data structures that grow with input size.