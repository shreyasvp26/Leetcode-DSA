// Problem: 169. Majority Element - https://leetcode.com/problems/majority-element/
// Boyer–Moore Voting Algorithm
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate = nums[i];
            }
            if(nums[i]==candidate) count++;
            else count--;
        }
        return candidate;
    }
};

// Time Complexity: O(n) - The algorithm iterates through the input array once, where n is the size of the array. Therefore, the time complexity is linear, O(n).
// Space Complexity: O(1) - The algorithm uses a constant amount of extra space to store the candidate and count variables, regardless of the size of the input array. Therefore, the space