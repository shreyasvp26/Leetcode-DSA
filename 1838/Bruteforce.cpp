// Problem: 1838. Frequency of the Most Frequent Element - https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <vector>
using namespace std;
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi = 0;
    for (int i = 1; i < n; i++) {
      int temp = k;
      int cnt = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] - nums[j] <= temp) {
          temp -= (nums[i] - nums[j]);
          cnt++;
        } else
          break;
      }
      maxi = max(maxi, cnt);
    }
    return maxi;
  }
};

// This gives TLE as n goes over 10^5 and complexity is O(N^2) which is too slow
