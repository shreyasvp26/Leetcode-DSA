// 1283. Find the Smallest Divisor Given a Threshold - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int func(vector<int> &nums, int m){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%m == 0) sum += (nums[i]/m);
            else sum += (nums[i]/m)+1;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int h = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            h = max(h, nums[i]);
        }
        int l = 1;
        int ans = h;
        while(l<=h){
            int m = l + (h-l)/2;
            if(func(nums, m) <= threshold){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};

// Time Complexity: O(n log m) where n is the size of the array and m is the maximum element in the array
// Space Complexity: O(1)