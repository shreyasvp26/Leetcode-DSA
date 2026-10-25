// 4065. Rearrange Array by Removing Distinct Values - https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        while(true){
            bool added = false;
            for(auto &it : mpp){
                if(it.second > 0){
                    ans.push_back(it.first);
                    it.second--;
                    added = true;
                }
            }
            if(!added) break;
        }
        return ans;        
    }
};

// Time Complexity: O(n log n) - We use a map to count the occurrences of each number, which takes O(n log n) time. Then we iterate through the map and the original array to construct the answer, which takes O(n) time.
// Space Complexity: O(n) - We use a map to store the occurrences of each number, which requires additional space proportional to the number of distinct elements in the array.