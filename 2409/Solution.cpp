// 2409. Count Days Spent Together - https://leetcode.com/problems/count-days-spent-together/

#include <iostream>
using namespace std;

class Solution {
    int convert(string s) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }
        return day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);
        int start = max(a1, b1);
        int end = min(a2, b2);
        return max(0, end - start + 1);
    }
};

// Time Complexity: O(1) - The function performs a constant number of operations regardless of the input size.
// Space Complexity: O(1) - The function uses a fixed amount of space for variables and does not depend on the input size.