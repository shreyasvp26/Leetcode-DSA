// 875. Koko Eating Bananas - https://leetcode.com/problems/koko-eating-bananas/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    long long func(vector<int> nums, int m){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % m ==0) sum += (nums[i]/m);
            else sum += (nums[i]/m) + 1;
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int high = INT_MIN, low = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            high = max(high, nums[i]);
        }
        int ans = low;
        while(low<=high){
            int m = low + (high-low)/2;
            if(func(nums, m) <= h){
                ans = m;
                high = m-1;
            }
            else low = m+1;
        }
        return ans;
    }
};

// Time Complexity: O(n log m) where n is the size of the array and m is the maximum element in the array
// Space Complexity: O(1)