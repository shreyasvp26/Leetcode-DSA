// 13. Roman to Integer - https://leetcode.com/problems/roman-to-integer/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int integer = 0;
        for(int i=0; i<s.length();i++){
            if(s[i]=='I' && i+1<s.length() && s[i+1]=='V'){
                integer += 4;
                i++;
            }
            else if(s[i]=='I' && i+1<s.length() && s[i+1]=='X'){
                integer += 9;
                i++;
            }
            else if(s[i]=='X' && i+1<s.length() && s[i+1]=='L'){
                integer += 40;
                i++;
            }
            else if(s[i]=='X' && i+1<s.length() && s[i+1]=='C'){
                integer += 90;
                i++;
            }
            else if(s[i]=='C' && i+1<s.length() && s[i+1]=='D'){
                integer += 400;
                i++;
            }
            else if(s[i]=='C' && i+1<s.length() && s[i+1]=='M'){
                integer += 900;
                i++;
            }
            else if(s[i]=='I') integer += 1;
            else if(s[i]=='V') integer += 5;
            else if(s[i]=='X') integer += 10;
            else if(s[i]=='L') integer += 50;
            else if(s[i]=='C') integer += 100;
            else if(s[i]=='D') integer += 500;
            else integer += 1000;
        }
        return integer;
    }
};

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1)