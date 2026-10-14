// Problem: 189. Rotate Array - https://leetcode.com/problems/rotate-array/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

// Time Complexity: O(n) - where n is the number of elements in the input vector nums. We traverse the entire vector three times for reversing.
// Space Complexity: O(1) - we are using a constant amount of extra space for