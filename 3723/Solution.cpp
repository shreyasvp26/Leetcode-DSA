// Problem: 3723. Maximum Sum of Squares - https://leetcode.com/problems/maximum-sum-of-squares/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i=0; i<num; i++){
            for(int j=9; j>=0; j--){                
                if(sum >= j){
                    sum -= j;
                    ans += '0' + j;
                    break;
                }
            }
            if(i==num-1 && sum==0) return ans;
        }
        return "";
    }
};

// Time Complexity: O(num * 10) = O(num)
//Space Complexity: O(num) for the answer string