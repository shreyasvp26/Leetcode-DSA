// 2149. Rearrange Array Elements by Sign - https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int posIndex = 0;
        int negIndex = 1;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0){
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            else{
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};

// Time Complexity: O(n) - We traverse the input array once to rearrange the elements.
// Space Complexity: O(n) - We use an additional array to store the rearranged elements.