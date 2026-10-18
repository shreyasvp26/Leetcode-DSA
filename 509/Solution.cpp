// 509. Fibonacci Number - https://leetcode.com/problems/fibonacci-number/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// Time Complexity: O(2^n) - The time complexity of this recursive solution is exponential, as it makes two recursive calls for each non-base case input.   
// Space Complexity: O(n) - The space complexity is linear, as the maximum depth of the recursion tree is n, which corresponds to the input value n.