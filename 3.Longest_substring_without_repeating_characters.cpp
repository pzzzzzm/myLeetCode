// Given a string s, find the length of the longest substring without repeating characters.

#include "_structs.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int res = 0;
        int tempSize = 0;

        for (int i = 0; i < s.size(); i ++) {
            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = i;
                tempSize ++;
            }
            else {
                res = max(res, tempSize);
                tempSize = min(i - charMap[s[i]], ++tempSize); 
                charMap[s[i]] = i;
            }
        }

        res = max(res, tempSize);
        return res;
    }
};

int main() {
    Solution sol;
    string input = "tmmzuxt";
    cout << sol.lengthOfLongestSubstring(input);
    return 0;
}
