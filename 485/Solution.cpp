// Problem: 485. Max Consecutive Ones - https://leetcode.com/problems/max-consecutive-ones/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, cnt = 0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]==1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
};

// Time Complexity: O(n) - where n is the number of elements in the input vector nums. We traverse the entire vector once.
// Space Complexity: O(1) - we are using a constant amount of extra space for variables maxi and cnt, regardless of the input size.