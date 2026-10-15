// Problem: 26. Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[j-1]!=nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;        
    }
};

// Time Complexity: O(n) - The loop iterates through the array once, where n is the number of elements in the input array.
// Space Complexity: O(1) - The algorithm uses a constant amount of extra space,