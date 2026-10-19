// 1752. Check if Array Is Sorted and Rotated - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return true;
        int mini = nums[0];
        int flag = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]) {
                if(flag) return false;
                flag = 1;
            }
            if(!flag && nums[i] < mini) return false;
            if(flag && nums[i] > mini) return false;
        }
        return true;
    }
};

// Time Complexity: O(n) --> Worst: O(n) -- Average: O(n) -- Best: O(1) if the array is sorted and not rotated
// Space Complexity: O(1)