// Problem: 3727.Maximum Alternating Sum of Squares - https://leetcode.com/problems/maximum-alternating-sum-of-squares/


#include <vector>
using namespace std;
class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {
    sort(nums.begin(), nums.end(),
         [&](int a, int b) { return abs(a) > abs(b); });
    int n = nums.size(), p = 0;
    if (n & 1)
      p = n / 2 + 1;
    else
      p = n / 2;
    long long ans = 0;
    for (int i = 0; i < p; i++) {
      ans += pow(nums[i], 2);
    }
    for (int i = p; i < n; i++) {
      ans -= pow(nums[i], 2);
    }
    return ans;
  }
};

// Time Complexity: O(n log n) for sorting the array
// Space Complexity: O(1) for using constant space