// Problem: 153. Find Minimum in Rotated Sorted Array - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        int l = 0, h = arr.size()-1;
        int mini = arr[0];
        if(arr[l]<arr[h]) return arr[l];
        while(l<=h){
            int m = l + (h-l)/2;
            if(arr[m]>=arr[0]) l = m+1;
            else h = m-1;
        }
        return arr[l];
    }
};

// Time Complexity: O(log n) - The algorithm uses binary search, which divides the search space in half with each iteration, leading to logarithmic time complexity.
// Space Complexity: O(1) - The algorithm uses a constant amount of extra space, regardless of the input size.