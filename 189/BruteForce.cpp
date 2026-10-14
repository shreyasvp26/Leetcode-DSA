// Problem: 189. Rotate Array - https://leetcode.com/problems/rotate-array/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int first = nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = first;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for(int i=0;i<k;i++){
            rotateArrayByOne(nums);
        }
    }
};

// Time Complexity: O(n*k) - where n is the number of elements in the input vector nums and k is the number of rotations. We are rotating the array k times, and each rotation takes O(n) time.
// Space Complexity: O(1) - we are not using any extra space for the rotation