// 4093. Maximize Sum After At Most K Digit Rearrangements - https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    long long func(int num) {
        string s = to_string(num);
        sort(s.rbegin(), s.rend());   
        long long rearranged = stoll(s);
        return rearranged - num;
    }
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        priority_queue<long long> gain;
        for(int i=0; i<n; i++){
            sum += nums[i];
            gain.push(func(nums[i]));
        }
        while(k--){
            int el = gain.top();
            gain.pop();
            sum += el;
        }
        return sum;
    }
};

// Time Complexity: O(n log n) - For each number in the input array, we convert it to a string, sort its digits in descending order, and calculate the difference. Sorting the digits takes O(d log d) time, where d is the number of digits in the number. Since d is at most 10 (for numbers up to 10^9), this can be considered constant time. Therefore, the overall time complexity is dominated by the sorting of the input array, which takes O(n log n) time.
// Space Complexity: O(n) - We use a priority queue to store the gain for each number, which requires additional space proportional to the number of elements in the input array.