// 18. 4Sum - https://leetcode.com/problems/4sum/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int a=0; a<n-3; a++){
            if(a>0 && nums[a]==nums[a-1]){
                continue;
            }
            for(int b=a+1; b<n-2; b++){
                if(b>a+1 && nums[b]==nums[b-1]){
                    continue;
                }
                int c = b+1, d = n-1;
                while(c<d){
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target){
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c<d && nums[c]==nums[c-1]) c++;
                        while(c<d && nums[d]==nums[d+1]) d--;
                    }
                    else if(sum<target) c++;
                    else d--;
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^3) - We have three nested loops, one for the first element, one for the second element, and one for the two pointers.
// Space Complexity: O(1) - We are not using any extra space except for the output vector, which is not counted towards space complexity.