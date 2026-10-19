// 34. Find First and Last Position of Element in Sorted Array - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int firstPos(vector<int> &nums, int x){
        int l = 0, h = nums.size()-1;
        int lb = 0;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]>=x){
                lb = m;
                h = m-1;
            }
            else l = m+1;
        }
        if(nums[lb]==x) return lb;
        return -1;
    }
    int lastPos(vector<int> &nums, int x){
        int l = 0, h = nums.size()-1;
        int lb = nums.size();
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]>x){
                lb = m;
                h = m-1;
            }
            else l = m+1;
        }
        if(lb-1 >=0 && nums[lb-1]==x) return lb-1;
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1, -1};
        return {firstPos(nums, target), lastPos(nums, target)};
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(1)