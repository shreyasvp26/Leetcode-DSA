// Problem: 189. Rotate Array - https://leetcode.com/problems/rotate-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(k);
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }
        for(int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};


// Time Complexity: O(n) - where n is the number of elements in the input vector nums. We traverse the entire vector once to copy elements and once to shift them.
// Space Complexity: O(k) - we are using extra space for the temporary vector temp which stores k elements.
