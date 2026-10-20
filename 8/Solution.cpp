// 8. String to Integer (atoi) - https://leetcode.com/problems/string-to-integer-atoi/

//My Code
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool isNeg = false, strt = true;
        for(char i : s){
            if(strt && i == ' '){
                continue;
            }
            if(strt && ((i == '-' || i=='+') || (i>='0' && i<='9'))){
                if(i=='-') isNeg = true;
                strt = false;
                if((i == '+' || i=='-')) continue;
            }
            if(!(i>='0' && i<='9')) break;
            int digit = i - '0';
            ans = ans*10 + digit;
            if (!isNeg && ans > INT_MAX) return INT_MAX;
            if (isNeg && ans > 2147483648LL) return INT_MIN;
        }
        if(isNeg) ans = -ans;
        return ans;
    }
};

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1)

//Better code (seperating responsibilities) 

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        // Step 2: Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        // Step 3: Process digits
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if (sign * ans >= INT_MAX) {
                if (sign == 1) return INT_MAX;
                if (sign == -1 && ans >= 2147483648LL) return INT_MIN;
            }
            i++;
        }
        return sign * ans;
    }
};