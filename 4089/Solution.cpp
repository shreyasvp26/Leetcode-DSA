// 4089. Count Subarrays With Loose Bounds - https://leetcode.com/problems/count-subarrays-with-loose-bounds/


#include <iostream>
#include <vector>
using namespace std;    
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int bre = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                bre = i+1;
                continue;
            }
            ans += (i-bre+1);
        }
        return ans;
    }
};

// Time Complexity: O(n) - We traverse the array once to count valid subarrays.
// Space Complexity: O(1) - We use a constant amount of space for variables ans and bre.