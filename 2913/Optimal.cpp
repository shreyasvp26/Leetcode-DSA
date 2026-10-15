// Problem: 2913. Subarrays Distinct Element Sum of Squares I - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            unordered_set<int> s;
            for(int j=i; j<n; j++){
                s.insert(nums[j]);
                ans += pow(s.size(), 2);
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^2) - The outer loop iterates over all possible starting indices of subarrays, and the inner loop iterates over all possible ending indices of subarrays. The unordered_set operations (insert and size) are O(1) on average.
// Space Complexity: O(n) - The unordered_set is used to store distinct elements in the current subarray, which can take up to O(n) space in the worst case.