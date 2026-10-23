// 3644. Maximum K to Sort a Permutation - https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (k == -1) k = nums[i];
                else k &= nums[i];
            }
        }
        return max(k, 0);
    }
};

// Time Complexity: O(n), where n is the size of the input array nums. We iterate through the array once to find the maximum k.
// Space Complexity: O(1), as we use a constant amount of extra space for variables k and n.