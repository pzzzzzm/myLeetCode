// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // vector<int> sumVector = {cardPoints[0]};
        // for (int i = 1; i < cardPoints.size(); i ++) {
        //     sumVector.push_back(cardPoints[i] + sumVector[i-1]);
        // }

        // if (k == cardPoints.size()) {
        //     return sumVector.back();
        // }

        // int maximum = sumVector.back() - *(sumVector.end()-k-1);

        // for (int i = 0; i < k; i ++) {
        //     int tempMax = sumVector[i] + sumVector.back() - *(sumVector.end()-k+i);
        //     if (tempMax > maximum) {
        //         maximum = tempMax;
        //     }
        // }

        // return maximum;

        int n = cardPoints.size();
        int res = 0;

        for (int i = 0; i < k; i ++) {
            res += cardPoints[i];
        }

        if (n == k) return res;

        int tempMax = res;

        for (int i = 0; i < k; i ++) {
            tempMax = tempMax - cardPoints[k-1-i] + cardPoints[n-i-1];
            if (tempMax > res) {
                res = tempMax;
            }
        }

        return res;
        
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    int res = sol.maxScore(cardPoints, k);
    cout << res;
    return 0;
}

// sliding window
// each sliding costs constant time (add a value and sub a value)