// 560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mpp.find(sum-k)!=mpp.end()) {
                cnt += mpp[sum-k];
            }
            mpp[sum] += 1;
        }
        return cnt;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)