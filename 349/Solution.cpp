// Problem: 349. Intersection of Two Arrays - https://leetcode.com/problems/intersection-of-two-arrays/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersection;
        int n1 = nums1.size(), n2 = nums2.size();
        int i=0, j=0;
        while(i<n1 && j< n2){
            if(nums1[i]==nums2[j]){
                if(intersection.size()==0 || intersection.back()!=nums1[i]){
                    intersection.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return intersection;
    }
};

// Time Complexity: O(nlogn + mlogm) - The sorting of both arrays takes O(nlogn) and O(mlogm) time respectively, where n and m are the sizes of the two input arrays. The while loop iterates through both arrays once, which takes O(n + m) time. Therefore, the overall time complexity is dominated by the sorting step, resulting in O(nlogn + mlogm).
// Space Complexity: O(min(n, m)) - The space complexity is determined by the size of the intersection vector, which can hold at most min(n, m) elements in the worst case