// Problem: 2913. Subarrays Distinct Element Sum of Squares I - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                unordered_set<int> s;
                int cnt = 0;
                for(int k=i; k<=j; k++){
                    if(s.find(nums[k])==s.end()) {
                        cnt++;
                        s.insert(nums[k]);
                    }
                }
                ans += pow(cnt, 2);
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^3) - The outer two loops iterate over all possible subarrays, and the innermost loop checks for distinct elements in each subarray.
// Space Complexity: O(n) - The unordered_set is used to store distinct elements in the current subarray, which can take up to O(n) space in the worst case.