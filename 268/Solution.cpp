// Problem: 268. Missing Number - https://leetcode.com/problems/missing-number/


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;
        int n = nums.size();
        return n*(n+1)/2 - sum;
    }
};

// Time Complexity: O(n) - The loop iterates through the array once, where n is the number of elements in the input array.
// Space Complexity: O(1) - The algorithm uses a constant amount of extra space,