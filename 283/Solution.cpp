// Problem: 283. Move Zeroes - https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        while(i<n && nums[i]!=0) i++;
        for(int j = i+1; j<n; j++){
            if(i<n && nums[j]!=0){
                swap(nums[i], nums[j]);
            }
            while(i<n && nums[i]!=0) i++;
        }
    }
};

// Time Complexity: O(n) - where n is the number of elements in the input vector nums. We are traversing the array once to find the first zero and then again to swap non-zero elements with zeros.
// Space Complexity: O(1) - we are not using any extra space for the operation