// 4092. Binary Digit Score - https://leetcode.com/problems/binary-digit-score/

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = __builtin_popcount(a);
        int s2 = __builtin_popcount(b);
        if(s1 >= s2) return s1*s2;
        return s2/s1;
    }
};

// Time Complexity: O(1) - The function calculates the binary digit score using built-in functions that operate in constant time.
// Space Complexity: O(1) - The function uses a constant amount of space for its calculations, regardless of the input values.