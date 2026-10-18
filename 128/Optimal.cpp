// Problem: 128. Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        int maxi = 0;
        for(auto num : s){
            int cnt = 1;
            int el = num;
            if(s.find(el-1)!=s.end()) continue;
            while(s.find(el+1)!=s.end()){
                cnt += 1;
                el += 1;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

// Time Complexity: O(n) - We are traversing the array once to insert elements into the set and then traversing the set to find the longest consecutive sequence.
// Space Complexity: O(n) - We are using an unordered_set to store the elements of the array.

/*
Emphasis & Reasoning:

Continue condition: if (x-1) exists, skip. 
This ensures we only start from the beginning of a sequence. 
Without it, we'd start from every element, causing O(N²) because each sequence would be traversed multiple times.

Iterate over set, not nums: Set contains unique elements. 
If we iterate over nums, duplicates would cause repeated processing of the same number, wasting time. 
Iterating over set ensures each unique number is considered once, crucial for O(N) even with duplicates.

Why it works: Each element is visited at most twice (once as a potential start, once while extending a sequence), giving O(N).
*/