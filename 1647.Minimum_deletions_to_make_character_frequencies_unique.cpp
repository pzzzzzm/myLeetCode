// A string s is called good if there are no two different characters in s that have the same frequency.

// Given a string s, return the minimum number of characters you need to delete to make s good.

// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.


#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        
        // map<char, int> charFreq;
        // for (int i = 0; i < s.size(); i ++) {
        //     if (charFreq.find(s[i]) == charFreq.end()) {
        //         charFreq[s[i]] = 1;
        //     }
        //     else {
        //         charFreq[s[i]] += 1;
        //     }
        // }

        // priority_queue<int, vector<int>> freqQueue;
        // for (auto iter = charFreq.begin(); iter != charFreq.end(); iter ++) {
        //     freqQueue.push(iter->second);
        // }



        // // int currentFreq = freqQueue.top()+1;
        // // // freqQueue.pop();
        // // int numOfRepeatedFreq = 0;
        // // int res = 0;

        // // while (currentFreq > 0) {
        // //     if (currentFreq > freqQueue.top() || freqQueue.size() == 0) {
        // //         numOfRepeatedFreq = max(0, numOfRepeatedFreq-1);
        // //         res += numOfRepeatedFreq;
        // //         currentFreq -= 1;
        // //     }
        // //     else {
        // //         while (freqQueue.size() != 0 && currentFreq == freqQueue.top()) {
        // //             numOfRepeatedFreq += 1;
        // //             freqQueue.pop();
        // //         }
        // //         // numOfRepeatedFreq -= 1;
        // //     }
        // // }

        // int res = 0;
        // int currentFreq = freqQueue.top();
        // freqQueue.pop();

        // while (freqQueue.size() != 0) {
        //     if (currentFreq == 0) {
        //         res += freqQueue.top();
        //     }
        //     else if (freqQueue.top() >= currentFreq) {
        //         res += freqQueue.top() - currentFreq + 1;
        //         currentFreq -= 1;
        //     }
        //     else {
        //         currentFreq = freqQueue.top();
        //     }
        //     freqQueue.pop();
        // }

        // return res;


        vector<int> charFreq(26, 0);
        for (int i = 0; i < s.size(); i ++) {
            charFreq[s[i]-'a'] += 1;
        }
        sort(charFreq.begin(), charFreq.end(), greater<int>());

        int res = 0;
        int currentFreq = charFreq[0];
        for (int i = 1; i < 26; i ++) {
            if (charFreq[i] == 0) break;
            if (currentFreq == 0) {
                res += charFreq[i];
            }
            else if (currentFreq <= charFreq[i]) {
                res += charFreq[i] - currentFreq + 1;
                currentFreq -= 1;
            }
            else {
                currentFreq = charFreq[i];
            }
        }

        return res;


    }
};

int main() {
    Solution sol;
    string s = "bbcebab";
    int res = sol.minDeletions(s);

    cout << res;
    return 0;
}