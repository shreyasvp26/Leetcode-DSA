// 75. Sort Colors - https://leetcode.com/problems/sort-colors/

// Dutch National Flag Problem
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Time Complexity: O(n) - We are traversing the array only once.
// Space Complexity: O(1) - We are not using any extra space.