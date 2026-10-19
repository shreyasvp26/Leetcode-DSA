// 560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum==k) cnt++;
            }
        }
        return cnt;
    }
};


// Time Complexity: O(n^2)
// Space Complexity: O(1)