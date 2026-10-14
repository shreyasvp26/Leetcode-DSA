// 1 - Two Sum - https://leetcode.com/problems/two-sum/

#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

// Time Complexity: O(n^2) - We traverse the list containing n elements twice. For every element, we try to find its complement by looping through the rest of the list which takes O(n) time.
// Space Complexity: O(1) - We do not use any extra space.