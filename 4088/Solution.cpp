// 4088. Difference Between Peaks and Valleys - https://leetcode.com/problems/difference-between-peaks-and-valleys/ 


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int sumPeak = 0, sumValley = 0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) sumPeak += nums[i];
            if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) sumValley += nums[i];
        }
        return sumPeak - sumValley;
    }
};

// Time Complexity: O(n) - We traverse the array once to find peaks and valleys.
// Space Complexity: O(1) - We use a constant amount of space for sumPeak and sumValley.