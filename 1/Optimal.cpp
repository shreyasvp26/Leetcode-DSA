// 1 - Two Sum - https://leetcode.com/problems/two-sum/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int el = nums[i];
            int need = target - nums[i];
            if(mpp.find(need)!=mpp.end()){
                return {mpp[need], i};
            }
            mpp[el] = i;
        }
        return {};
    }
};

// Time Complexity: O(n) - We traverse the list containing n elements only once. Each look up in the table costs only O(1) time.
// Space Complexity: O(n) - The extra space required depends on the number of items stored in the hash table, which stores at most n elements.