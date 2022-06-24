// You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < n and set the value of arr at index i to x.
// You may repeat this procedure as many times as needed.

// Return true if it is possible to construct the target array from arr, otherwise, return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {

        int targetMax;
        int targetMaxIndex;
        long sum;

        if (target.size() == 1) {
            if (target[0] == 1) {
                return true;
            }
            else {
                return false;
            }
        }

        while (true) {
            targetMax = target[0];
            targetMaxIndex = 0;
            sum = 0;

            for (int i = 0; i < target.size(); i ++) {
                if (target[i] > targetMax) {
                    targetMax = target[i];
                    targetMaxIndex = i;
                }
                sum += target[i];
            }

            if (targetMax == 1) {
                return true;
            }

            if (2*targetMax < sum+1) {
                return false;
            }

            target[targetMaxIndex] = ((targetMax-1) % (sum-targetMax)) + 1;
        }

    }
};


int main() {
    Solution sol;
    vector<int> target = {9, 3, 5};
    bool res = sol.isPossible(target);
    cout << res;
    return 0;
}

// recursion could meet limitation if too many steps.
// but it's feasible as the steps could be reduced by mod.
// be careful for the overflow, check constrains.

// failed submissions are caused by:
    // 1. runtime limitation due to too many recursion steps 
    // 2. divided by 0, check situtation of the next step carefully
    // 3. int overflow  