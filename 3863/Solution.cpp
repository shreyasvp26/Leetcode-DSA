// 3863. Minimum Operations to Sort a String - https://leetcode.com/problems/minimum-operations-to-sort-a-string/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        return 3;
    }
};

// Time Complexity: O(n) where n is the length of the string s.
// Space Complexity: O(1) since we are using constant space.

/*
 Sometimes we have to just observe the test cases mulriple times and find a pattern to solve the problem. 
This problem is one of those problems. 
The solution is based on the observation that if the string is already sorted, we don't need to do anything. 
If the string has only two characters, we can't sort it in any way. 
If the first character is the minimum or the last character is the maximum, we can sort it in one operation. 
If any character in between is the minimum or maximum, we can sort it in two operations. 
Otherwise, we need three operations to sort the string.
*/