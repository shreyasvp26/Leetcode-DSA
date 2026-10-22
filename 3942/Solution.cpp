// 3942. Minimum Operations to Sort a Permutation - https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    if (count <= 1) return 0; 
    reverse(nums.begin(), nums.end());
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    reverse(nums.begin(), nums.end()); 
    if (count <= 1) return 1; 
    return -1; 
}
public:
    int minOperations(vector<int>& nums) {
        int chk = check(nums);
        if(chk == -1) return -1;
        int n = nums.size();
        int idx = find(nums.begin(), nums.end(), 0) - nums.begin();
        if (chk == 0) return min(idx, n - idx + 2);
        return min(n - idx, idx + 2);
    }
};

// Time Complexity: O(n) - The check function iterates through the nums vector twice, resulting in a linear time complexity. The minOperations function also performs a linear search to find the index of 0, leading to an overall time complexity of O(n).
// Space Complexity: O(1) - The solution uses a constant amount of extra space, as it only utilizes a few integer variables and does not use any additional data structures that scale with the input size.