// 4083. Minimum Deletions to Make Array Sharp - https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0;
        for(int i=1; i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity: O(n) - We traverse the array once to count the number of deletions needed.
// Space Complexity: O(1) - We use a constant amount of space for the counter variable.