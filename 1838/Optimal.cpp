// Problem: 1838. Frequency of the Most Frequent Element - https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <vector>
using namespace std;
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long l = 0, r = 0;
    long long total = 0, res = 0;
    while (r < n) {
      total += nums[r];
      while (nums[r] * (r - l + 1) > total + k) {
        total -= nums[l];
        l++;
      }
      res = max(res, r - l + 1);
      r++;
    }
    return (int)res;
  }
};

// The sliding window approach keeps the time complexity to O(N log N) which is
// optimal.