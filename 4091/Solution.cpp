// 4091. Count Magical Substring Pairs II - https://leetcode.com/problems/count-magical-substring-pairs-ii/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<int> atMost(string &s, int d) {
        int n = s.size();
        vector<int> cnt(26, 0);
        vector<int> res(n, 0);
        int left = 0;
        int distinct = 0;
        for (int right = 0; right < n; right++) {
            if (cnt[s[right] - 'a'] == 0) {
                distinct++;
            }
            cnt[s[right] - 'a']++;
            while (distinct > d) {
                cnt[s[left] - 'a']--;
                if (cnt[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            res[right] = right - left + 1;
        }
        return res;
    }

    vector<vector<int>> exact(string &s) {
        int n = s.size();
        vector<vector<int>> freq(n, vector<int>(27, 0));
        vector<int> prev(n, 0);
        for (int d = 1; d <= 26; d++) {
            vector<int> curr = atMost(s, d);
            for (int i = 0; i < n; i++) {
                freq[i][d] = curr[i] - prev[i];
            }
            prev = curr;
        }
        return freq;
    }
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> leftFreq = exact(s);
        vector<vector<int>> rightFreq = exact(rev);
        long long ans = 0;
        for (int j = 0; j < n - 1; j++) {
            int rightIndex = n - j - 2;
            for (int d = 1; d <= 26; d++) {
                ans += 1LL * leftFreq[j][d] * rightFreq[rightIndex][d];
            }
        }
        return ans;
    }
};


// Time Complexity: O(n * 26) - We traverse the string multiple times to calculate frequencies for each distinct character count.
// Space Complexity: O(n * 26) - We use a 2D vector to store frequencies for each character count at each index.