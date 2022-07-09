// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iterator>

using namespace std;

class Solution {
public:
    // bool isInterleave(string s1, string s2, string s3) {
    //     return checkFirst(0, 0, 0, s1, s2, s3);
    // }

    // bool checkFirst(int i1, int i2, int i3, string str1, string str2, string str3) {
    //     if (i3 != str3.size()) {
    //         if (str3[i3] == str1[i1]) {
    //             i1 ++;
    //             i3 ++;
    //             if (checkFirst(i1, i2, i3, str1, str2, str3)) return true;
    //             i1 --;
    //             i3 --;
    //         }
    //         if (str3[i3] == str2[i2]) {
    //             i2 ++;
    //             i3 ++;
    //             if (checkFirst(i1, i2, i3, str1, str2, str3)) return true;
    //             i2 --;
    //             i3 --;
    //         }
    //         return false;
    //     }
    //     else {
    //         if (i1 == str1.size() && i2 == str2.size()) return true;
    //         return false;
    //     }
    // }
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s3.size() != s1.size()+s2.size()) return false;

        vector<bool> dp(s2.size()+1, 0);
        for (int i = 0; i <= s1.size(); i ++) {
            for (int j = 0; j <= s2.size(); j ++) {
                if (i == 0 && j == 0) {
                    dp[j] = 1;
                    continue;
                }
                else if (i > 0 && dp[j] == 1) {
                    if (s1[i-1] == s3[i+j-1]) {
                        dp[j] = 1;
                        continue;
                    }
                }
                else if (j > 0 && dp[j-1] == 1) {
                    if (s2[j-1] == s3[i+j-1]) {
                        dp[j] = 1;
                        continue;
                    }
                }
                dp[j] = 0;
            }
        }
        return dp[dp.size()-1];
        
    }

};

int main() {
    Solution sol;
    // string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    // string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    // string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    string s1 = "a";
    string s2 = "";
    string s3 = "c";
    cout << sol.isInterleave(s1, s2, s3);
    return 0;
}

// recursion may exceed time limit.
// use 2d dp -> 1d dp