// Problem: 9. Palindrome Number - https://leetcode.com/problems/palindrome-number/

class Solution {
  int reverseNumber(int n) {
    long long rev = 0;
    while (n > 0) {
      int digit = n % 10;
      rev = rev * 10 + digit;
      n /= 10;
    }
    return (int)rev;
  }

public:
  bool isPalindrome(int n) {
    if (n < 0)
      return false;
    int rev = reverseNumber(n);
    if (rev == n)
      return true;
    return false;
  }
};

// Time Complexity : O(log10 N)